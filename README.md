# Projeto ESP32 MQTT - Monitoramento de Temperatura e Umidade

> **🌟 PROJETO BASE - GLOBAL SOLUTION 2025**
> 
> Este projeto serve como base para o desenvolvimento da Global Solution 2025.
> Os alunos devem utilizar esta estrutura como ponto de partida para implementar
> suas soluções inovadoras de IoT com ESP32.

⚠️ **ATENÇÃO - IMPORTANTE PARA LABORATÓRIOS FIAP**
> Para o correto funcionamento do projeto nos laboratórios da FIAP, é necessário:
> 1. Solicitar ao professor a liberação das portas no firewall:
>    - Porta 1883 (MQTT Broker)
>    - Porta 1880 (Node-RED Dashboard)
> 2. Sem essa liberação, não será possível:
>    - Conectar ao broker MQTT
>    - Visualizar os dados no dashboard Node-RED
>    - Testar a comunicação do projeto

## Descrição

O projeto implementa um sistema IoT que:
- Conecta um ESP32 a uma rede Wi-Fi
- Realiza leituras de temperatura e umidade usando um sensor DHT22
- Lê valores de um potenciômetro para controle analógico
- Envia os dados para um broker MQTT a cada 10 segundos
- Inclui identificação do dispositivo e informações de rede

## Recursos do Servidor

O projeto utiliza um servidor dedicado com os seguintes recursos já configurados:

- **Broker MQTT**: Já configurado no servidor
- **Node-RED**: Interface de visualização disponível em `172.208.54.189:1880`

## Pré-requisitos

- Visual Studio Code
- Extensão PlatformIO IDE
- Conta no Wokwi (para simulação)
- Licença do Wokwi Simulator (necessária para simulação no VS Code)

## Instalação e Configuração

### 1. Clone o Repositório

```bash
git clone https://github.com/2TDS-GS2025/iot-esp32-gs.git
cd iot-esp32-gs
```

### 2. Abra o Projeto no VS Code

1. Abra o Visual Studio Code
2. Vá em File > Open Folder
3. Selecione a pasta do projeto clonado
4. Aguarde o PlatformIO reconhecer o projeto

### 3. Configuração do Wokwi Simulator

1. Instale a extensão "Wokwi Simulator" no VS Code
2. Após a instalação, você será solicitado a fazer login na sua conta Wokwi
3. É necessário ter uma licença válida do Wokwi Simulator

### 4. Instalação das Dependências

O projeto utiliza as seguintes bibliotecas (já configuradas no platformio.ini):
- ArduinoJson
- Adafruit DHT sensor library
- Adafruit Unified Sensor
- PubSubClient

**Importante:** Na primeira vez que abrir o projeto, aguarde o PlatformIO baixar e instalar todas as dependências.

### 5. Configuração do Código

No arquivo `q1/src/main.cpp`, ajuste as seguintes variáveis conforme necessário:
```cpp
const char* ID        = "ID_do_Grupo";     // Seu ID de grupo
const char* moduleID  = "Meu_ESP32";       // ID do seu ESP32
```

## Estrutura do Projeto

```
iot-esp32-gs/
├── q1/
│   └── src/
│       └── main.cpp          # Código principal
├── platformio.ini            # Configuração do PlatformIO
└── README.md                 # Este arquivo
```

## Formato dos Dados

O JSON enviado tem o seguinte formato:
```json
{
    "ID": "ID_do_Grupo",
    "Sensor": "Meu_ESP32",
    "IP": "xxx.xxx.xxx.xxx",
    "MAC": "XX:XX:XX:XX:XX:XX",
    "Temperatura": xx.xx,
    "Umidade": xx.xx,
    "Potenciometro": xxxx
}
```

## Visualização dos Dados

Os dados enviados pelo seu ESP32 podem ser monitorados de duas formas:

1. **Node-RED**
   - Acesse `172.208.54.189:1880` em seu navegador
   - Os dados de todos os dispositivos conectados podem ser visualizados em tempo real

2. **Monitor Serial**
   - Os dados também são exibidos no monitor serial do ESP32
   - Útil para debug e verificação local das leituras

## Créditos

Este projeto é baseado no trabalho original do Professor Arnaldo Viana:
[Repositório Original](https://github.com/arnaldojr/iot-esp32-wokwi-vscode.git)

## Suporte

Para dúvidas ou problemas:
1. Verifique as issues no repositório
2. Consulte a documentação das bibliotecas utilizadas
3. Entre em contato com o professor ou monitores da disciplina 