/* Library Initialization */
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

/* Pin Initialization */
// Relay
const int R1 = D1;
const int R2 = D2;
const int R3 = D3;
const int R4 = D4;
const int R5 = D5;
const int R6 = D6;
const int R7 = D7;
const int R8 = D8;

/* Variable Initialization */
// Wifi
const char ssid             = "Techkom";
const char password         = "8283452008";
// MQTT
const char* mqttServer      = "IP";
const int   mqttPort        = 0000;
const char* mqttUser        = "User";
const char* mqttPassword    = "Password";
const char* clientID        = "Relay";
// Setting ESPClient
WiFiClient espClient;
PubSubClient client;

void setup() { 
 client.setClient(espClient):
 client.setServer(mqttServer,mqttPort,callbackMQTT)
 Serial.begin(115200);
}

void loop(){
 wifi();
}

void wifi(){
 WiFi.begin(ssid, password);
 for (int k=0; k<=5; k++){
  if(WiFi.status() != WL_CONNECTED){
   delay(500);
  } else if (WiFi.status() == WL_CONNECTED){
   Serial.println("Connected");
   Serial.print("IP Address: ");
   Serial.println(WiFi.localIP());
  } else (
   Serial.println("Not Connected");
  )
  delay(500);
 }
}

void jsonGet(){

}

void jsonSent(){
 const size_t capacity = 2*JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(4);
 DynamicJsonDocument doc(size_t);
 JsonObject obj = doc.to<JsonObject>();

 obj["device"] = clientID;

 JsonObject relay = doc.createNestedObject("RStat");
}

void mqttConnect(){
 while(!client.connected()){
  if (client.connect(clientID,[mqttUser,mqttPassword])){
   Serial.println("mqtt connected")
  } else {
   Serial.print("mqtt not connected, Error State : ");
   Serial.println(client.state());
  }
 }
}