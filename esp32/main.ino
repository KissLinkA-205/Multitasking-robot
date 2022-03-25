#include <WiFi.h>
#include <SPI.h>

#define LED_PIN 15

#define MOVEMENT_X 33  // ось X джойстика, отвечающего за движение робота
#define MOVEMENT_Y 32  // ось Y джойстика, отвечающего за движение робота
#define CAMERA_X 35    // ось X джойстика, отвечающего за перемещение головы робота
#define CAMERA_Y 34    // ось Y джойстика, отвечающего за перемещение головы робота

const int BASE_AXIS_VALUE = 1700;
const int AXIS_INFELICITY = 150;

const int FORWARD_MOVEMENT_CODE = 1;
const int BACK_MOVEMENT_CODE = 2;
const int RIGHT_MOVEMENT_CODE = 3;
const int LEFT_MOVEMENT_CODE = 4;
const int STOP_MOVEMENT_CODE = 0;

const char* ROBOT_SSID = "Multitasking_robot";
const char* ROBOT_PASSWORD =  "robot123";
const uint16_t ROBOT_PORT = 65432;
const char* ROBOT_IP = "192.168.1.23";
WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOVEMENT_X, INPUT);
  pinMode(MOVEMENT_Y, INPUT);
  pinMode(CAMERA_X, INPUT);
  pinMode(CAMERA_Y, INPUT);

  WiFi.begin(ROBOT_SSID, ROBOT_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_PIN, LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("...");
    delay(500);
  }
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());

  while (!client.connect(ROBOT_IP, ROBOT_PORT)) {
    digitalWrite(LED_PIN, LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Connection to host failed");
    delay(500);
  }
  Serial.println("Connected to server successful!");
  digitalWrite(LED_PIN, HIGH);

}

void loop() {
  //Serial.print(client.readString());
  int movementX = analogRead(MOVEMENT_X);
  int movementY = analogRead(MOVEMENT_Y);
  int cameraX = analogRead(CAMERA_X);
  int cameraY = analogRead(CAMERA_Y);

  Serial.print("MOVEMENT_X: "); Serial.print(movementX); Serial.print(", MOVEMENT_Y: "); Serial.print(movementY); Serial.print('\n');
  Serial.print("CAMERA_X: "); Serial.print(cameraX); Serial.print(", CAMERA_Y: "); Serial.print(cameraY); Serial.print('\n');

  char message[4] = { getDirectionMovementCode(movementX, movementY) + '0', ':', getDirectionMovementCode(cameraX, cameraY) + '0', '\0' };
  client.print(message);
  //client.print(':');
  //client.print(getDirectionMovementCode(cameraX, cameraY));
  delay(300);

}

int getDirectionMovementCode(int movementX,  int movementY) {
  int result = STOP_MOVEMENT_CODE;

  if (movementY > BASE_AXIS_VALUE + AXIS_INFELICITY) {
    result = FORWARD_MOVEMENT_CODE;
  } else if (movementY < BASE_AXIS_VALUE - AXIS_INFELICITY) {
    result = BACK_MOVEMENT_CODE;
  } else if (movementX > BASE_AXIS_VALUE + AXIS_INFELICITY) {
    result = LEFT_MOVEMENT_CODE;
  } else if (movementX < BASE_AXIS_VALUE - AXIS_INFELICITY) {
    result = RIGHT_MOVEMENT_CODE;
  }

  return result;
}
