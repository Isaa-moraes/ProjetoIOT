#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

// 1. Configurações da Rede e do Broker
const char* ssid = "SENAI-DEV2";
const char* password = "desenvolvimento";

// COLOQUE AQUI O IP DO SEU COMPUTADOR (obtido com 'ipconfig' no CMD)
const char* mqtt_server = "192.168.0.100"; 
const int mqtt_port = 1883;

// Credenciais de acesso ao Mosquitto
const char* mqtt_user = "aluno_01";
const char* mqtt_pass = "desenvolvimento";

// 2. Tópico MQTT e Pino do Hardware
const char* mqtt_topic_pub = "aula/teste";
const int LED_PIN = 2; // Pino do LED integrado/protoboard

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  // Configuração do pino do LED
  pinMode(LED_PIN, OUTPUT);
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

  // Configuração do Servidor MQTT
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  // Conecta ao Broker MQTT caso esteja desconectado
  if (!client.connected()) {
    Serial.print("Conectando ao Mosquitto MQTT...");
    if (client.connect("ESP32_Cliente", mqtt_user, mqtt_pass)) {
      Serial.println(" Sucesso!");
      
      // 1. Publica a mensagem no tópico aula/teste
      if (client.publish(mqtt_topic_pub, "comunicação feita com sucesso!")) {
        Serial.println("Mensagem enviada para o broker: 'comunicação feita com sucesso!'");
      } else {
        Serial.println("Falha ao enviar mensagem.");
      }

      // 2. Aciona a sequência do LED
      Serial.println("Ligando o LED...");
      digitalWrite(LED_PIN, HIGH); // Liga o LED
      
      delay(2000); // Mantém ligado por 2 segundos

      Serial.println("Desligando o LED...");
      digitalWrite(LED_PIN, LOW); // Desliga o LED

    } else {
      Serial.print(" Falhou, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }

  client.loop(); // Mantém o cliente ativo
}
