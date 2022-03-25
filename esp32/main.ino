#include <WiFi.h>
#include <SPI.h>

#define LED_PIN 15

const char* ROBOT_SSID = "Multitasking_robot";
const char* ROBOT_PASSWORD =  "robot123";
const uint16_t ROPOT_RORT = 65432;
const char* ROBOT_IP = "192.168.1.23";
WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  WiFi.begin(ROBOT_SSID, ROBOT_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_PIN, LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("...");
    delay(500);
  }
  digitalWrite(LED_PIN, HIGH);

}

void loop() {
  

}
