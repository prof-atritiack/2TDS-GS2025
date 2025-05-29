# Projeto ESP32 MQTT - Monitoramento de Temperatura e Umidade

> **🌟 PROJETO BASE - GLOBAL SOLUTION 2025**
> 
> Este projeto serve como base para o desenvolvimento da Global Solution 2025.
> Os alunos devem utilizar esta estrutura como ponto de partida para implementar
> suas soluções inovadoras de IoT com ESP32.

Este projeto implementa um sistema de monitoramento usando ESP32 que envia dados de temperatura e umidade via MQTT.

## Estrutura do Projeto

### Diretórios e Arquivos Importantes

- `q1/src/` - Diretório principal do código fonte
  - `main.cpp` - Arquivo principal contendo toda a lógica do programa, incluindo:
    - Configurações de Wi-Fi e MQTT
    - Leitura do sensor DHT22
    - Formatação e envio dos dados em JSON
    - Gerenciamento de conexões

### Dependências do Projeto

O projeto utiliza as seguintes bibliotecas:
- WiFi (nativa)
- PubSubClient (requer instalação)
- ArduinoJson (requer instalação)
- DHT (requer instalação)
- Adafruit Sensor (requer instalação)

## ⚠️ Instruções Importantes

### Primeira Execução

1. Ao abrir o projeto pela primeira vez, **aguarde** a instalação completa de todas as dependências
   - O processo de instalação é automático mas pode levar alguns minutos
   - A barra de status inferior mostrará o progresso das instalações
   - **Não tente compilar ou executar o projeto antes da conclusão das instalações**

### Alterações no Código

1. Sempre que fizer qualquer alteração no código:
   - Execute o Build do projeto (Ctrl+Shift+B ou botão Build)
   - Aguarde a conclusão do Build antes de tentar executar
   - Verifique se não há erros no console

### Simulação com Wokwi

O projeto é compatível com o simulador Wokwi. Para utilizar:

1. Você pode usar o diagrama fornecido no projeto copiando o arquivo `.json` do Wokwi online
2. O diagrama inclui todas as conexões necessárias para o sensor DHT22
3. As configurações do simulador já estão otimizadas para este projeto

## Configurações

- O LED onboard está configurado no pino 2
- O sensor DHT22 está configurado no pino 4
- As credenciais Wi-Fi e MQTT podem ser modificadas no arquivo `main.cpp`

## Funcionamento

O sistema:
1. Conecta-se à rede Wi-Fi configurada
2. Estabelece conexão com o broker MQTT
3. A cada 10 segundos:
   - Lê dados do sensor DHT22
   - Formata os dados em JSON
   - Envia para o broker MQTT
   - Pisca o LED onboard como feedback

## Observações

- Mantenha as configurações do broker MQTT conforme especificadas para compatibilidade com a VM do professor
- Verifique sempre o Monitor Serial para acompanhar o funcionamento do sistema

## Descrição

O projeto implementa um sistema IoT que:
- Conecta um ESP32 a uma rede Wi-Fi
- Realiza leituras de temperatura e umidade usando um sensor DHT22
- Envia os dados para um broker MQTT a cada 10 segundos
- Inclui identificação do dispositivo e informações de rede

## Recursos do Servidor

O projeto utiliza um servidor dedicado com os seguintes recursos já configurados:

- **Broker MQTT**: Já configurado no servidor
- **Node-RED**: Interface de visualização disponível em `172.208.54.189:1880`

**Importante:** Não é necessário configurar seu próprio broker ou Node-RED. Os dados enviados pelo seu ESP32 podem ser visualizados diretamente no Node-RED através do endereço fornecido.

## Pré-requisitos

- Visual Studio Code
- Extensão PlatformIO IDE
- Conta no Wokwi (para simulação)
- Licença do Wokwi Simulator (necessária para simulação no VS Code)
- Git (para clonar o repositório)

## Instalação e Configuração

### 1. Clone o Repositório

```bash
git clone https://github.com/arnaldojr/iot-esp32-wokwi-vscode.git
cd iot-esp32-wokwi-vscode
```

### 2. Abra o Projeto no VS Code

1. Abra o Visual Studio Code
2. Vá em File > Open Folder
3. Selecione a pasta do projeto clonado
4. Aguarde o PlatformIO reconhecer o projeto

### 3. Configuração do Wokwi Simulator

**IMPORTANTE: Esta etapa é crucial e deve ser realizada antes de prosseguir**

1. Instale a extensão "Wokwi Simulator" no VS Code
2. Após a instalação, você será solicitado a fazer login na sua conta Wokwi
3. É necessário ter uma licença válida do Wokwi Simulator
   - A licença pode ser obtida em [wokwi.com](https://wokwi.com/)
   - Sem a licença ativa, não será possível simular o projeto no VS Code
4. Após ativar a licença, reinicie o VS Code

### 4. Instalação das Dependências

O projeto utiliza as seguintes bibliotecas (já configuradas no platformio.ini):
- ArduinoJson
- Adafruit DHT sensor library
- Adafruit Unified Sensor
- PubSubClient

**Importante:** Na primeira vez que abrir o projeto, aguarde o PlatformIO baixar e instalar todas as dependências. Isso pode levar alguns minutos.

### 5. Configuração do Código

O arquivo principal `q1/src/main.cpp` já está configurado com:
- Conexão Wi-Fi usando a rede Wokwi-GUEST (simulação)
- Broker MQTT pré-configurado no servidor
- Pino do sensor DHT22 definido como GPIO4

### 6. Ajuste as Configurações

No arquivo `main.cpp`, ajuste as seguintes variáveis conforme necessário:
```cpp
const char* ID        = "ID_do_Grupo";     // Seu ID de grupo
const char* moduleID  = "Meu_ESP32";       // ID do seu ESP32
```

**Nota:** Não é necessário alterar as configurações do broker MQTT, pois o servidor já está configurado e pronto para uso.

## Simulação no Wokwi

1. O projeto está configurado para usar a rede Wi-Fi do próprio Wokwi
2. Não é necessário configurar senha Wi-Fi para a simulação
3. O broker MQTT já está pré-configurado

## Estrutura do Projeto

```
iot-esp32-wokwi-vscode/
├── q1/
│   └── src/
│       └── main.cpp          # Código principal
├── platformio.ini            # Configuração do PlatformIO
└── README.md                 # Este arquivo
```

## Funcionamento

O sistema:
1. Inicializa o ESP32 e o sensor DHT22
2. Conecta-se à rede Wi-Fi
3. Estabelece conexão com o broker MQTT
4. A cada 10 segundos:
   - Realiza leitura de temperatura e umidade
   - Monta um JSON com os dados
   - Envia para o broker MQTT
   - Pisca o LED onboard para feedback visual

## Formato dos Dados

O JSON enviado tem o seguinte formato:
```json
{
    "ID": "ID_do_Grupo",
    "Sensor": "Meu_ESP32",
    "IP": "xxx.xxx.xxx.xxx",
    "MAC": "XX:XX:XX:XX:XX:XX",
    "Temperatura": xx.xx,
    "Umidade": xx.xx
}
```

## Visualização dos Dados

Os dados enviados pelo seu ESP32 podem ser monitorados de duas formas:

1. **Node-RED**
   - Acesse `172.208.54.189:1880` em seu navegador
   - Os dados de todos os dispositivos conectados podem ser visualizados em tempo real
   - Interfaces gráficas personalizadas estão disponíveis para visualização dos dados

2. **Monitor Serial**
   - Os dados também são exibidos no monitor serial do ESP32
   - Útil para debug e verificação local das leituras

## Créditos

Este projeto é baseado no trabalho original do Professor Arnaldo Viana:
[Repositório Original](https://github.com/arnaldojr/iot-esp32-wokwi-vscode.git)

## Suporte

Para dúvidas ou problemas:
1. Verifique as issues no repositório original
2. Consulte a documentação das bibliotecas utilizadas
3. Entre em contato com o professor ou monitores da disciplina 