
# Air Quality ESP

Este repositório contém o código para o dispositivo ESP32, que faz parte do projeto de TCC focado na medição da qualidade do ar em ambientes fechados. O dispositivo utiliza sensores de qualidade do ar para capturar dados como temperatura, umidade, concentração de partículas (PM) e gases inflamáveis (MQ-5). Esses dados são enviados para o Firebase Realtime Database, onde podem ser consumidos pela API e exibidos em um aplicativo iOS.

## Componentes Utilizados

- **ESP32**: Microcontrolador responsável por coletar e enviar os dados.
- **DHT22**: Sensor de temperatura e umidade.
- **GP2Y1010AU0F**: Sensor de partículas no ar (PM).
- **MQ-5**: Sensor de gases inflamáveis.
- **Firebase Realtime Database**: Armazenamento dos dados capturados pelo ESP32.

## Funcionalidades

- **Coleta de Dados**: O ESP32 coleta informações dos sensores conectados, como temperatura, umidade, nível de partículas no ar e concentração de gases inflamáveis.
- **Envio de Dados em Tempo Real**: Os dados coletados são enviados para o Firebase Realtime Database em tempo real através de WiFi.
- **Configuração via OTA**: Suporte para atualizações Over-the-Air (OTA) do firmware do dispositivo.

## Sensores Utilizados

### DHT22
- **Função**: Mede a temperatura e a umidade relativa.
- **Ligação**: O pino de dados é conectado a um dos pinos GPIO do ESP32.

### GP2Y1010AU0F
- **Função**: Mede a concentração de partículas no ar (PM).
- **Ligação**: Conectado aos pinos analógicos do ESP32.

### MQ-5
- **Função**: Detecta gases inflamáveis, como metano e GLP.
- **Ligação**: Conectado a um pino analógico para leitura do nível de gás no ambiente.

## Uso

Uma vez carregado o código no ESP32, o dispositivo começará a coletar dados dos sensores e enviá-los para o Firebase Realtime Database. A API Node.js disponível [neste repositório](https://github.com/joaogeneroso/air-quality-api) poderá ser utilizada para acessar e manipular esses dados, que serão consumidos pelo app iOS.
