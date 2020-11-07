/* Library Initialization */
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

/* Pin Initialization */
// Ultrasonic
const int ultPP = 7; // Ultrasonic Ping Pin
const int ultEP = 6; // Ultrasonic Echo Pin
// ADS1115
Adafruit_ADS1115 ads(0x49);

/* Variable Initalization */
// Ultrasonic
long duration, inches, cm;
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
 // Ultrasonic
 pinMode(ultPP, OUTPUT);
 pinmode(ultEP, INPUT);
 // ADS
 ads.setGain(GAIN_ONE);
 ads.begin();
}

void loop(){
 wifi();
 ultrasonic();
}

void ultrasonic(){
 digitalWrite(ultPP, LOW);
 delayMicroseconds(2);
 digitalWrite(ultPP, HIGH);
 delayMicroseconds(10);
 digitalWrite(ultPP, LOW);
 duration = pulseIn(ultEP, HIGH);
 inches = MTI(duration);
 cm = MTC(duration);
 Serial.print(inches);
 Serial.print("in, ");
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();
 delay(100);
}

long MTI (long microseconds) {
 return microseconds / 74 / 2;
}

long MTC (long microseconds) {
 return microseconds / 29 / 2;
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