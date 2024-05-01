#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <PubSubClient.h> 
#include <Adafruit_SSD1306.h>
#include "DHT.h" // Librería para el sensor DHT

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

WiFiClient espClient;
PubSubClient client2(espClient);

// Replace with your network credentials
const char* ssid = "Adrian";
const char* password = "123456ad";
const char* mqtt_server = "192.168.185.135";
const int mqtt_port = 1883;
const char* mqtt_client_id = "ESP32Client";

WiFiClientSecure client;

// Pin del sensor de sonido
int luz = 12;
int sensorSonido = 5;
int dhtPin = 18;
int sonido = 0;
int estadoBoton = 0;

// Parámetros del sensor DHT
#define DHTTYPE DHT11 // Tipo de sensor DHT (puedes cambiarlo a DHT22 si usas ese)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(sensorSonido, INPUT);
  pinMode(luz, OUTPUT);
  
  // Inicializar el sensor DHT
  dht.begin();

  // Inicializar la pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  // Conectar a Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red Wifi...");
  }
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Conectar al broker MQTT
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
  payload[length] = '\0';
  String val = String((char*)payload);
  Serial.println(val);
}

void loop() {
  // Mantener la conexión MQTT activa
  if (!client2.connected()) {
    if (client2.connect(mqtt_client_id)) {
      Serial.println("Reconexión exitosa al broker MQTT");
      client2.subscribe("topic_name"); // Suscribirse a un tema si es necesario
    } else {
      Serial.println("Fallo al reconectar al broker MQTT");
    }
  }
  
  client2.loop();

  // Leer sensor de sonido y sensor DHT
  int var = digitalRead(sensorSonido);
  int estadoBoton = digitalRead(dhtPin);

  // Controlar luces y publicar eventos MQTT
  if (var == HIGH || estadoBoton == LOW) {
    Serial.println("encendido");
    digitalWrite(luz, HIGH);
    sonido++;
    if (estadoBoton == LOW) {
      client2.publish("dht", "1");
      Serial.println("Publicado dht");
      digitalWrite(luz, HIGH);
    } 
    if (var == HIGH) {
      client2.publish("sound2", "1");
      Serial.println("Publicado sound");
      digitalWrite(luz, HIGH);
    } 
  } 

  // Apagar luces y publicar eventos MQTT
  if (sonido == 2) {
    Serial.println("apagado");
    digitalWrite(luz, LOW);
    sonido = 0;
    client2.publish("dht", "0");
    client2.publish("sound", "0");
  }

  // Leer temperatura y humedad
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  // Imprimir temperatura y humedad en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  // Publicar temperatura y humedad en el servidor MQTT
  char tempString[8];
  char humString[8];
  dtostrf(temperatura, 4, 2, tempString);
  dtostrf(humedad, 4, 2, humString);
  client2.publish("temperatura", tempString);
  client2.publish("humedad", humString);

  // Mostrar temperatura en la pantalla OLED
  mostrarTemperaturaEnPantalla(temperatura);

  delay(10000);
}

void mostrarTemperaturaEnPantalla(float temperatura) {
  // Mostrar temperatura en la pantalla OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Temperatura:");
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print(temperatura);
  display.print(" C");
  display.display();
}
