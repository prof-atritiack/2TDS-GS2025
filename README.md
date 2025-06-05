# Projeto ESP32 IoT - Global Solution 2025

> **🌟 PROJETO BASE - GLOBAL SOLUTION 2025**
> 
> ⚠️ **IMPORTANTE**: Este projeto serve APENAS como referência técnica para o desenvolvimento da Global Solution 2025.
> Os alunos NÃO devem utilizar este código diretamente. Em vez disso, devem desenvolver suas próprias 
> soluções inovadoras de IoT com ESP32, utilizando este material apenas como guia de implementação.

## 🔄 Opções de Implementação

Este repositório oferece duas opções de implementação para seu projeto IoT:

### 1️⃣ MQTT com Node-RED (Pasta Q1)
**Características**:
- Protocolo MQTT para comunicação IoT
- Visualização de dados via Node-RED
- Maior flexibilidade na manipulação dos dados
- Possibilidade de integração com diversos serviços
- Suporte a múltiplos dispositivos simultâneos

### 2️⃣ ThingSpeak (Pasta Q2)
**Características**:
- Implementação direta e simplificada
- Plataforma pronta para visualização
- Gráficos e análises integrados
- Rápida configuração inicial
- Interface web intuitiva

> 💡 **Dica**: Cada implementação possui características específicas. Analise as funcionalidades e escolha a que melhor atende aos requisitos do seu projeto.

## ⚠️ ATENÇÃO - IMPORTANTE PARA LABORATÓRIOS FIAP

> Para o correto funcionamento do projeto nos laboratórios da FIAP, é necessário:
> 
> 1. Solicitar ao professor a liberação das portas no firewall:
>    - Porta 1883 (MQTT Broker)
>    - Porta 1880 (Node-RED Dashboard)
> 2. Sem essa liberação, não será possível:
>    - Conectar ao broker MQTT
>    - Visualizar os dados no dashboard Node-RED
>    - Testar a comunicação do projeto

## 📝 Estrutura do Projeto

O repositório contém dois projetos de exemplo:

```
2TDS-GS2025/
├── q1/                      # Projeto MQTT com Node-RED
│   └── src/
│       └── main.cpp        # Código principal MQTT
├── q2/                      # Projeto ThingSpeak
│   └── src/
│       └── main.cpp        # Código principal ThingSpeak
├── platformio.ini          # Configuração PlatformIO
└── README.md               # Documentação
```

## 📡 Pasta Q1 - Monitoramento via MQTT e Node-RED

### Descrição

O projeto Q1 implementa um sistema IoT completo que:

**Conectividade**
- Conecta um ESP32 a uma rede Wi-Fi
- Estabelece comunicação com broker MQTT
- Gerencia reconexões automáticas

**Sensores e Dados**
- Leitura de temperatura e umidade (DHT22)
- Leitura de potenciômetro (controle analógico)
- Envio periódico de dados (10 segundos)
- Feedback visual por LED

**Identificação**
- ID do grupo
- ID do módulo
- Endereço IP
- Endereço MAC

### Recursos do Servidor Q1

O projeto utiliza um servidor dedicado com:

- **Broker MQTT**: 
  - Endereço: `172.208.54.189`
  - Porta: `1883`
  - Usuário e senha já configurados

- **Node-RED**: 
  - Interface visual em `172.208.54.189:1880`
  - Dashboard para monitoramento em tempo real
  - Gráficos e indicadores personalizados

### Formato dos Dados Q1

O JSON enviado segue este formato:
```json
{
    "ID": "ID_do_Grupo",          // Identificador do grupo
    "Sensor": "Meu_ESP32",        // Nome do dispositivo
    "IP": "xxx.xxx.xxx.xxx",      // IP local
    "MAC": "XX:XX:XX:XX:XX:XX",   // Endereço MAC
    "Temperatura": xx.xx,         // Em graus Celsius
    "Umidade": xx.xx,            // Em porcentagem
    "Potenciometro": xxxx        // Valor 0-4095
}
```

### Configuração do Código Q1

Em `q1/src/main.cpp`, configure:
```cpp
const char* ID        = "ID_do_Grupo";     // Seu identificador
const char* moduleID  = "Meu_ESP32";       // Nome do seu ESP32
```

## 📊 Pasta Q2 - Integração com ThingSpeak

### Descrição

A pasta `q2` contém um projeto alternativo que demonstra a integração com a plataforma ThingSpeak para visualização e análise de dados IoT.

### Configuração do ThingSpeak

1. **Pré-requisitos**
   - Criar uma conta no [ThingSpeak](https://thingspeak.com)
   - Criar um novo canal no ThingSpeak
   - Obter o Channel ID e Write API Key

2. **Configurações no Código**
   Em `q2/src/main.cpp`, configure:
   ```cpp
   unsigned long channelID = SEU_CHANNEL_ID;        // Substitua pelo seu Channel ID
   const char* writeAPIKey = "SUA_WRITE_API_KEY";   // Substitua pela sua Write API Key
   ```

### Funcionalidades do Projeto Q2

- Conexão automática com WiFi
- Envio de até 4 campos de dados para o ThingSpeak
- Intervalo de envio de 20 segundos (respeita limite gratuito)
- Feedback via monitor serial
- Reconexão automática em caso de perda de conexão

### Estrutura dos Dados Q2

O projeto envia 4 campos (fields) para o ThingSpeak:
```cpp
field1: valor1  // Primeiro valor
field2: valor2  // Segundo valor
field3: valor3  // Terceiro valor
field4: valor4  // Quarto valor
```

## ⚙️ Configuração do Ambiente

### Pré-requisitos

1. **Software**
   - Visual Studio Code
   - Extensão PlatformIO IDE
   - Git (para clonar o repositório)

2. **Simulação**
   - Conta Wokwi
   - Licença Wokwi Simulator
   - Extensão Wokwi no VS Code

### Instalação

1. **Clone o Repositório**
   ```bash
   git clone https://github.com/prof-atritiack/2TDS-GS2025.git
   cd 2TDS-GS2025
   ```

2. **Configuração do VS Code**
   1. Abra o VS Code
   2. File > Open Folder
   3. Selecione a pasta `2TDS-GS2025`
   4. Aguarde o PlatformIO inicializar

3. **Configuração do Wokwi**
   1. Instale a extensão Wokwi
   2. Faça login na sua conta
   3. Verifique a licença ativa

### Dependências

O projeto utiliza as seguintes bibliotecas:
- ArduinoJson (JSON)
- DHT sensor library (Sensor)
- Adafruit Unified Sensor (Base)
- PubSubClient (MQTT)
- ThingSpeak (apenas para Q2)

> ⚠️ **Importante**: Aguarde a instalação completa das dependências antes de compilar!

## 🛠️ Criação e Inserção de Diagramas Wokwi

### Como criar um novo diagrama no Wokwi Online

1. Acesse [https://wokwi.com/](https://wokwi.com/)
2. Clique em **"New Project"** e escolha o microcontrolador desejado (ex: ESP32).
3. Monte seu circuito utilizando os componentes disponíveis.
4. Salve o projeto e clique em **"Share"** para copiar o link ou baixe o arquivo `diagram.json`.

### Como inserir e editar diagramas neste projeto

1. **Adicione o arquivo do diagrama:**
   - Baixe o arquivo `diagram.json` do seu projeto Wokwi.
   - Coloque o arquivo na pasta correspondente do seu projeto local (exemplo: `q1/diagram.json` ou `q2/diagram.json`).

2. **Edição do diagrama:**
   - Você pode editar o arquivo `diagram.json` diretamente pelo editor de texto (VS Code) ou reimportá-lo no Wokwi para ajustes visuais.
   - Para editar no Wokwi, clique em **"Import Project"** e selecione seu `diagram.json`.

3. **Simulação:**
   - Com o arquivo `diagram.json` na pasta do projeto, utilize a extensão Wokwi no VS Code para simular seu circuito junto ao código fonte.

> **Dica:** Mantenha o arquivo `diagram.json` atualizado e versionado junto ao seu código para facilitar revisões e simulações futuras.

## 🔍 Monitor Serial

O monitor serial (115200 baud rate) exibe informações detalhadas:

### Inicialização
```
Conectando ao Wi-Fi.....
Wi-Fi conectado!
IP: 192.168.1.100
MAC Address: A4:CF:12:BF:7A:E5
Conectando ao Broker MQTT...
Conectado ao Broker!
```

### Possíveis Erros
```
Reconectando Wi-Fi...     // Perda de conexão
Erro na leitura do DHT    // Falha no sensor
Falha na conexão. Estado: -2   // Problema MQTT
```

O LED onboard (GPIO2) pisca após cada envio bem-sucedido!

## Visualização dos Dados

1. **Node-RED**
   - Acesse: `172.208.54.189:1880`
   - Visualização em tempo real
   - Gráficos interativos

2. **Monitor Serial**
   - Debug local
   - Verificação de erros
   - Teste de funcionamento

## Personalização do Node-RED ⚡

O Node-RED é uma ferramenta poderosa que permite expandir significativamente as capacidades do seu projeto. Recomenda-se fortemente que você desenvolva seus próprios fluxos para atender às necessidades específicas do seu projeto.

### Possibilidades de Expansão

1. **Integração com APIs Externas**
   - Conexão com serviços de previsão do tempo
   - Integração com APIs de notificação
   - Webhooks para sistemas externos
   - Automação com serviços em nuvem

2. **Banco de Dados**
   - Armazenamento histórico de leituras
   - Análise de tendências
   - Backup de dados
   - Consultas personalizadas
   
3. **Dashboards Personalizados**
   - Gráficos em tempo real
   - Indicadores personalizados
   - Painéis de controle interativos
   - Visualizações específicas para seu caso de uso

4. **Lógica de Negócio**
   - Processamento de dados
   - Filtros e transformações
   - Regras de negócio
   - Alertas condicionais

### Dicas de Implementação

- Comece com fluxos simples e incremente gradualmente
- Use nodes de debug para verificar o processamento dos dados
- Documente seus fluxos com nodes de comentário
- Faça backup regular dos seus fluxos
- Considere implementar autenticação para seus endpoints

### Recursos para Node-RED

- [Node-RED Library](https://flows.nodered.org/)
- [Documentação Oficial](https://nodered.org/docs/)
- [Guia de Boas Práticas](https://nodered.org/docs/user-guide/writing-flows)

## Créditos

Este projeto é baseado no trabalho original do Professor Arnaldo Viana:
[Repositório Original](https://github.com/arnaldojr/iot-esp32-wokwi-vscode.git)

- Este projeto utiliza o **GitHub Copilot** e o **Claude 3.5 Sonnet** como assistentes de programação para geração e revisão de código, documentação e automação de tarefas.

## Suporte

Precisa de ajuda?
1. Verifique as issues no repositório
2. Consulte a documentação das bibliotecas
3. Contate o professor ou monitores

## Referências e Recursos

### Documentação Técnica
- [Documentação ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [Biblioteca PubSubClient](https://pubsubclient.knolleary.net/)
- [ArduinoJson](https://arduinojson.org/)
- [Wokwi](https://docs.wokwi.com/)

### Desenvolvimento Assistido por IA
Este projeto foi desenvolvido com auxílio de IA Generativa:
- **Modelo**: Claude 3.5 Sonnet
- **Plataforma**: Cursor IDE
- **Aplicação**: 
  - Geração e revisão de código
  - Documentação técnica
  - Debugging assistido
  - Otimização de código

### Recursos Educacionais
- [ESP32 - Primeiros Passos](https://randomnerdtutorials.com/getting-started-with-esp32/)
- [MQTT Essentials](https://www.hivemq.com/mqtt-essentials/)

## Uso com Placas Físicas

Para grupos que optarem por usar uma placa ESP32 física:

1. **Arquivo para Arduino**
   - Use o arquivo `q1/esp32_mqtt_dht22.ino`
   - Contém o mesmo código e funcionalidades do projeto

2. **Bibliotecas Necessárias**
   - `PubSubClient`
   - `ArduinoJson`
   - `DHT sensor library`
   - `Adafruit Unified Sensor`

3. **Configuração do Código**
   - Configure suas credenciais Wi-Fi:
     ```cpp
     const char* ssid = "SUA_REDE_WIFI";
     const char* password = "SUA_SENHA_WIFI";
     ```
   - Ajuste os identificadores:
     ```cpp
     const char* ID = "ID_do_Grupo";
     const char* moduleID = "Meu_ESP32";
     ```

4. **Conexões Físicas**
   - DHT22:
     - VCC → 3.3V
     - GND → GND
     - DATA → GPIO12
   - Potenciômetro:
     - VCC → 3.3V
     - GND → GND
     - SIGNAL → GPIO34
   - LED onboard está no GPIO2

> ⚠️ **Importante**: Verifique todas as conexões antes de energizar a placa e use resistores pull-up quando necessário.

## 📊 Pasta Q2 - Integração com ThingSpeak

A pasta `q2` contém um projeto alternativo que demonstra a integração com a plataforma ThingSpeak para visualização e análise de dados IoT.

### Configuração do ThingSpeak

1. **Pré-requisitos**
   - Criar uma conta no [ThingSpeak](https://thingspeak.com)
   - Criar um novo canal no ThingSpeak
   - Obter o Channel ID e Write API Key

2. **Configurações no Código**
   Em `q2/src/main.cpp`, configure:
   ```cpp
   unsigned long channelID = SEU_CHANNEL_ID;        // Substitua pelo seu Channel ID
   const char* writeAPIKey = "SUA_WRITE_API_KEY";   // Substitua pela sua Write API Key
   ```

3. **Dependências Adicionais**
   - Biblioteca ThingSpeak (será instalada automaticamente pelo PlatformIO)

### Funcionalidades do Projeto Q2

- Conexão automática com WiFi
- Envio de até 4 campos de dados para o ThingSpeak
- Intervalo de envio de 20 segundos (respeita limite gratuito)
- Feedback via monitor serial
- Reconexão automática em caso de perda de conexão

### Estrutura dos Dados

O projeto envia 4 campos (fields) para o ThingSpeak:
```cpp
field1: valor1  // Primeiro valor
field2: valor2  // Segundo valor
field3: valor3  // Terceiro valor
field4: valor4  // Quarto valor
```

### Visualização no ThingSpeak

1. Acesse sua conta no ThingSpeak
2. Navegue até seu canal
3. Visualize os gráficos em tempo real
4. Configure widgets e análises personalizadas

### Personalização

Você pode modificar o código para:
- Alterar o número de campos enviados
- Modificar o intervalo de envio
- Adicionar mais sensores
- Implementar lógicas específicas

> ⚠️ **Importante**: 
> - O plano gratuito do ThingSpeak permite atualizações a cada 15 segundos
> - Mantenha suas chaves API em segurança
> - Considere usar variáveis de ambiente para as credenciais