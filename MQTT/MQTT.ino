/* Library Initialization */
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

/* Pin Initialization */

/* Variable Initialization */
// Wifi
const char  ssid          = "Techkom";
const char  password      = "8283452008";
// MQTT
const char* mqttServer    = "IP":
const int   mqttPort      = 0000;
const char* mqttUser      = "User";
const char* mqttPassword  = "Password";
const char* client_ID     = "Tedmon";
// Setting ESPClient
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
 Serial.begin(115200);
}