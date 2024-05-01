#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <PubSubClient.h> 

WiFiClient espClient;
PubSubClient client2(espClient);

const char* ssid = "Adrian";
const char* password = "123456ad";
const char* mqtt_server = "192.168.185.135";
const int mqtt_port = 1883;
const char* mqtt_client_id = "ESP32Client";

WiFiClientSecure client;

const int sensorPIR = 34; // Pin donde está conectada la entrada del sensor PIR
const int buzzerPin = 25; // Pin donde está conectado el buzzer
int PIR = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPIR, INPUT_PULLUP); // Sensor PIR configurado como entrada
  pinMode(buzzerPin, OUTPUT); // Buzzer configurado como salida
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red Wifi...");
  }
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  client2.setServer(mqtt_server, mqtt_port);
  client2.setCallback(callback);
  
  if (client2.connect(mqtt_client_id)) {
    Serial.println("Conexión exitosa al broker MQTT");
    client2.subscribe("topic_name"); // Suscribirse a un tema si es necesario
  } else {
    Serial.println("Fallo al conectar al broker MQTT");
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length]='\0';
  String val = String((char*)payload);
  Serial.println(val);
}

void loop() {
  if (!client2.connected()) {
    if (client2.connect(mqtt_client_id)) {
      Serial.println("Reconexión exitosa al broker MQTT");
      client2.subscribe("topic_name"); // Suscribirse a un tema si es necesario
    } else {
      Serial.println("Fallo al reconectar al broker MQTT");
    }
  }
  
  client2.loop();

  PIR = digitalRead(sensorPIR);
  if (PIR == HIGH) {
    Serial.println("Movimiento detectado");
    client2.publish("pir", "1");
    digitalWrite(buzzerPin, HIGH); // Activar el buzzer
    delay(500); // Esperar medio segundo
    digitalWrite(buzzerPin, LOW); // Desactivar el buzzer
  } else {
    client2.publish("pir", "0");
  }
  delay(1000);
}
