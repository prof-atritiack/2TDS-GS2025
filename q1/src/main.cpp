/********************************************************************
 * Projeto: Envio de Dados MQTT com ESP32 - Global Solution 2025
 * Autor: André Tritiack
 * Placa: DOIT ESP32 DEVKIT V1
 * 
 * Descrição:
 * Este projeto conecta o ESP32 a uma rede Wi-Fi e a um Broker MQTT.
 * A cada 10 segundos, envia uma mensagem JSON contendo:
 * - ID do grupo
 * - ID do módulo
 * - IP local
 * - Dados de temperatura e umidade do sensor DHT22
 * 
 * Baseado no repositório original:
 * https://github.com/arnaldojr/iot-esp32-wokwi-vscode
 * Professor Arnaldo Viana - FIAP
 ********************************************************************/

//----------------------------------------------------------
// Bibliotecas já disponíveis no ambiente ESP32

#include <WiFi.h>

//----------------------------------------------------------
// Bibliotecas a instalar pelo Gerenciador de Bibliotecas

#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

//----------------------------------------------------------
// Definições e configurações

#define boardLED 2 // LED onboard
#define DHTPIN 4   // Pino de dados do DHT
#define DHTTYPE DHT22 // DHT22 (AM2302)

// Identificadores
const char* ID        = "ID_do_Grupo";
const char* moduleID  = "Meu_ESP32";

// Wi-Fi
const char* SSID      = "Wokwi-GUEST";
const char* PASSWORD  = "";

// MQTT Broker (NÃO ALTERE ESSAS CONFIGURAÇÕES, CASO QUEIRA USAR OS RECURSOS
// DA VM DISPONIBILIZADA PELO PROFESSOR)
const char* BROKER_MQTT  = "172.208.54.189";
const int   BROKER_PORT  = 1883;
const char* mqttUser     = "gs2025";
const char* mqttPassword = "q1w2e3r4";

// Tópico MQTT
#define TOPICO_PUBLISH  "2TDS/esp32/teste"

//----------------------------------------------------------
// Variáveis globais

WiFiClient espClient;
PubSubClient MQTT(espClient);
char buffer[256]; // Buffer para o JSON serializado
DHT dht(DHTPIN, DHTTYPE);

float temperatura;
float umidade;

//----------------------------------------------------------
// Conexão Wi-Fi

void initWiFi() {
    WiFi.begin(SSID, PASSWORD);
    Serial.print("Conectando ao Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC Address: ");
    Serial.println(WiFi.macAddress());
}

void reconectaWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Reconectando Wi-Fi...");
        initWiFi();
    }
}

//----------------------------------------------------------
// Conexão MQTT

void initMQTT() {
    MQTT.setServer(BROKER_MQTT, BROKER_PORT);
    while (!MQTT.connected()) {
        Serial.println("Conectando ao Broker MQTT...");
        if (MQTT.connect(moduleID, mqttUser, mqttPassword)) {
            Serial.println("Conectado ao Broker!");
        } else {
            Serial.print("Falha na conexão. Estado: ");
            Serial.println(MQTT.state());
            delay(2000);
        }
    }
}

void verificaConexoesWiFiEMQTT() {
    reconectaWiFi();
    if (!MQTT.connected()) {
        initMQTT();
    }
    MQTT.loop();
}

//----------------------------------------------------------
// Envio e feedback

void enviaEstadoOutputMQTT() {
    MQTT.publish(TOPICO_PUBLISH, buffer);
    Serial.println("Mensagem publicada com sucesso!");
}

void piscaLed() {
    digitalWrite(boardLED, HIGH);
    delay(300);
    digitalWrite(boardLED, LOW);
}

//----------------------------------------------------------
// Setup inicial

void setup() {
    Serial.begin(115200);
    pinMode(boardLED, OUTPUT);
    digitalWrite(boardLED, LOW);
    dht.begin();
    initWiFi();    
    initMQTT();
}

//----------------------------------------------------------
// Loop principal

void loop() {
    // Verifica e mantém conexões ativas com Wi-Fi e MQTT
    verificaConexoesWiFiEMQTT();

    // Leitura dos dados do sensor DHT
    temperatura = dht.readTemperature();
    umidade = dht.readHumidity();

    // Montagem do documento JSON
    StaticJsonDocument<300> doc;

    // 1. Identificação
    doc["ID"]     = ID;
    doc["Sensor"] = moduleID;

    // 2. Rede
    doc["IP"]     = WiFi.localIP();
    doc["MAC"]    = WiFi.macAddress();

    // 3. Dados de sensores
    if (!isnan(temperatura) && !isnan(umidade)) {
        doc["Temperatura"] = temperatura;
        doc["Umidade"] = umidade;
    } else {
        doc["Temperatura"] = "Erro na leitura";
        doc["Umidade"] = "Erro na leitura";
    }

    // Serializa JSON para string
    serializeJson(doc, buffer);

    // Exibe no monitor serial
    Serial.println(buffer);

    // Envia via MQTT
    enviaEstadoOutputMQTT();

    // Feedback visual
    piscaLed();

    // Intervalo de envio
    delay(10000);
}