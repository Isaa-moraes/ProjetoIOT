#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

// 1. Configurações da Rede e do Broker
const char* ssid = "SENAI-DEV2";
const char* password = "desenvolvimento";

const char* mqtt_server = "192.168.0.103"; 
const int mqtt_port = 1883;

const char* mqtt_user = "aluno_01";
const char* mqtt_pass = "desenvolvimento";

// 2. Tópico MQTT e Pino do Hardware atualizados conforme a atividade
const char* mqtt_topic = "sala/comando"; // Alterado conforme imagem 1 e 2
const int LED_PIN = 4;                   // Alterado para o pino D4 (GPIO 4) conforme imagem 1 e 3

WiFiClient espClient;
PubSubClient client(espClient);

// Função que processa os comandos recebidos do Dashboard (Callback)
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem chegou no tópico: ");
  Serial.println(topic);

  String mensagem = "";
  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i]; // Constrói a string a partir dos bytes
  }

  Serial.println("Conteúdo da mensagem: " + mensagem);

  // Lógica para ligar/desligar o LED conforme imagem 3
  if (mensagem == "LIGAR") {
    digitalWrite(LED_PIN, HIGH); // Liga o LED no pino D4
    Serial.println("LED LIGADO!");
  } 
  else if (mensagem == "DESLIGAR") {
    digitalWrite(LED_PIN, LOW);  // Desliga o LED no pino D4
    Serial.println("LED DESLIGADO!");
  }
}

void setup() {
  Serial.begin(115200);

  // Configuração do pino do LED
  pinMode(LED_PIN, OUTPUT); // Configura o pino D4 como saída (imagem 2)
  digitalWrite(LED_PIN, LOW); // Garante que inicia desligado

  // Conexão Wi-Fi
  Serial.print("Conectando ao Wi-Fi: ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi Conectado!");
  Serial.print("IP do ESP32: ");
  Serial.println(WiFi.localIP());

  // Configuração do Servidor MQTT e vinculação do Callback
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback); // Adiciona a escuta do callback (imagem 2)
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao Mosquitto MQTT...");
    if (client.connect("ESP32_Cliente", mqtt_user, mqtt_pass)) {
      Serial.println(" Sucesso!");
      
      // NOVA LINHA: Assina o tópico de comandos da sala (imagem 2)
      client.subscribe(mqtt_topic);
      Serial.print("Inscrito no tópico: ");
      Serial.println(mqtt_topic);

      // Envia uma mensagem de aviso para a Web informando que a placa ligou
      client.publish(mqtt_topic, "ESP32 Conectado e Pronto!");

    } else {
      Serial.print(" Falhou, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void loop() {
  // Mantém a conexão ativa
  if (!client.connected()) {
    reconnect();
  }
  
  // Fica escutando os comandos em tempo real
  client.loop(); 
}