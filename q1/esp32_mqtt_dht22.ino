/*
 * Projeto: Envio de Dados MQTT com ESP32 - Global Solution 2025
 * Autor: André Tritiack
 * Placa: DOIT ESP32 DEVKIT V1
 * 
 * Versão para Arduino IDE - Uso com placas físicas
 */

#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

// Definições de pinos
#define DHTPIN 12       // Pino de dados do DHT
#define DHTTYPE DHT22   // DHT22 (AM2302)
#define POTPIN 34       // Pino do potenciômetro
#define LED_BUILTIN 2   // LED onboard

// Configurações Wi-Fi
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";

// Configurações MQTT
const char* mqtt_server = "172.208.54.189";
const int mqtt_port = 1883;
const char* mqtt_user = "gs2025";
const char* mqtt_password = "q1w2e3r4";
const char* mqtt_topic = "2TDS/esp32/teste";

// Identificadores
const char* ID = "ID_do_Grupo";
const char* moduleID = "Meu_ESP32";

// Objetos
WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);
JsonDocument doc;
char buffer[256];

// Variáveis
float temperatura;
float umidade;
int valorPot;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect(moduleID, mqtt_user, mqtt_password)) {
      Serial.println("conectado");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(POTPIN, INPUT);
  
  Serial.begin(115200);
  
  setup_wifi();
  
  client.setServer(mqtt_server, mqtt_port);
  
  dht.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Leitura dos sensores
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();
  valorPot = analogRead(POTPIN);

  // Limpa o documento JSON
  doc.clear();

  // Monta o JSON
  doc["ID"] = ID;
  doc["Sensor"] = moduleID;
  doc["IP"] = WiFi.localIP().toString();
  doc["MAC"] = WiFi.macAddress();

  if (!isnan(temperatura) && !isnan(umidade)) {
    doc["Temperatura"] = temperatura;
    doc["Umidade"] = umidade;
  } else {
    doc["Temperatura"] = "Erro na leitura";
    doc["Umidade"] = "Erro na leitura";
  }

  doc["Potenciometro"] = valorPot;

  // Serializa o JSON
  serializeJson(doc, buffer);
  
  // Publica no MQTT
  client.publish(mqtt_topic, buffer);
  
  // Feedback visual
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);

  // Debug
  Serial.println(buffer);

  // Aguarda 10 segundos
  delay(10000);
} 