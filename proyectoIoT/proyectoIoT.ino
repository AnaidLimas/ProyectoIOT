#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <PubSubClient.h> 

WiFiClient espClient;
PubSubClient client2(espClient);

// Replace with your network credentials
const char* ssid = "Adrian"; //"Jerusalen";
const char* password = "123456ad"; //"*E8$J-Yk7J!-f4F";  //red: JERUSALEN contraseña: *E8$J-Yk7J!-f4F";
const char* mqtt_server = "192.168.185.135";
const int mqtt_port = 1883;
const char* mqtt_client_id = "ESP32Client";

WiFiClientSecure client;


int luz=12;
int sensorSonido=5;
int botonPin = 18;  // El número de pin del botón
int sonido=0;
int var=0;
int estadoBoton = 0;
const int sensorPIR = 34; // Pin donde está conectada la entrada del sensor PIR
int PIR = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (sensorSonido, INPUT);
  pinMode (luz, OUTPUT);
  pinMode(botonPin, INPUT_PULLUP); // Configuramos el pin del botón como entrada
  pinMode(sensorPIR, INPUT_PULLUP); // Sensor pir entrada


  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red Wifi...");
  }
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Connect to MQTT Broker
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

  // put your main code here, to run repeatedly:
  var=digitalRead(sensorSonido);
  estadoBoton = digitalRead(botonPin);  // Leemos el estado del botón
  PIR = digitalRead(sensorPIR);//Leemos el estado del del sensor PIR

if (var == HIGH || estadoBoton == LOW || PIR == HIGH) {
  Serial.println("encendido");
  digitalWrite(luz, HIGH);
  sonido=sonido+1;

  if (estadoBoton == LOW) {
    client2.publish("btn", "1");
    Serial.println("Publicado btn");
    digitalWrite(luz, HIGH);
  } 

  if (var == HIGH) {
    client2.publish("sound", "1");
    Serial.println("Publicado sound");
    digitalWrite(luz, HIGH);
  } 

  if (PIR == HIGH) {
    client2.publish("pir", "1");
    Serial.println("Publicado pir");
    digitalWrite(luz, HIGH);
  } 
} 

if (sonido == 2) {
  Serial.println("apagado");
  digitalWrite(luz, LOW);
  sonido = 0;
  client2.publish("btn", "0");
    client2.publish("sound", "0");
    client2.publish("pir", "0");
}



  // if (var==HIGH || estadoBoton == LOW || PIR == HIGH){
  //   Serial.println("encendido");
  //   digitalWrite(luz,HIGH);
  //   sonido=sonido+1;

  // // Publicar las variables en MQTT
  //  client2.publish("btn", "1"); // Publicar '1' cuando la condición se cumple
  //  client2.publish("sound", "1");
  //  client2.publish("pir", "1");
     
  // } 

  // if (sonido==2){
  //   Serial.println("apagado");
  //   digitalWrite(luz,LOW);
  //   sonido=0;

  //   // Publicar las variables en MQTT
  //   client2.publish("btn", "0");
  //   client2.publish("sound", "0");
  //   client2.publish("pir", "0");
    
  // }
    delay (10000);
}
