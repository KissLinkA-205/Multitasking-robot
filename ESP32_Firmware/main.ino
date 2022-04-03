#include <ESPManager.h>

ESPManager manager = ESPManager();


const int BASE_AXIS_VALUE = 1800;
const int AXIS_INFELICITY = 350;

const char FORWARD_MOVEMENT_CODE = 'f';
const char BACK_MOVEMENT_CODE = 'b';
const char RIGHT_MOVEMENT_CODE = 'r';
const char LEFT_MOVEMENT_CODE = 'l';
const char STOP_MOVEMENT_CODE = 's';

void setup() {
  manager.begin();
  /*pinMode(LED_PIN, OUTPUT);
  pinMode(motorchiki, OUTPUT);
  pinMode(soundPin, OUTPUT);
  pinMode(MOVEMENT_X, INPUT);
  pinMode(MOVEMENT_Y, INPUT);
  pinMode(CAMERA_X, INPUT);
  pinMode(CAMERA_Y, INPUT);

  pinMode(PIN_BUTTON, INPUT_PULLUP);
  delay(10000);*/
}

void loop() {
  manager.handle();

  /*int movementX = analogRead(MOVEMENT_X);
  int movementY = analogRead(MOVEMENT_Y);
  int cameraX = analogRead(CAMERA_X);
  int cameraY = analogRead(CAMERA_Y);
  char directionMovement = getDirectionMovementCode(movementX, movementY);
  int speedMovement = getSpeed(directionMovement, movementX);

  //Serial.print("MOVEMENT_X: "); Serial.print(movementX); Serial.print(", MOVEMENT_Y: "); Serial.print(movementY); Serial.print('\n');
  //Serial.print("CAMERA_X: "); Serial.print(cameraX); Serial.print(", CAMERA_Y: "); Serial.print(cameraY); Serial.print('\n');

  int buttonState = digitalRead(PIN_BUTTON);
  if (buttonState == 0) {
    menu.nextPage();
  }

  delay(300);
*/
}

char getDirectionMovementCode(int movementX,  int movementY) {
  char result = STOP_MOVEMENT_CODE;

  if (movementY > BASE_AXIS_VALUE + AXIS_INFELICITY) {
    result = FORWARD_MOVEMENT_CODE;
  } else if (movementY < BASE_AXIS_VALUE - AXIS_INFELICITY) {
    result = BACK_MOVEMENT_CODE;
  } else if (movementX > BASE_AXIS_VALUE + AXIS_INFELICITY) {
    result = RIGHT_MOVEMENT_CODE;
  } else if (movementX < BASE_AXIS_VALUE - AXIS_INFELICITY) {
    result = LEFT_MOVEMENT_CODE;
  }

  return result;
}

int getSpeed(char directionMovement, int positionMovement) {
  int result = 0;
  if (directionMovement == BACK_MOVEMENT_CODE || directionMovement == LEFT_MOVEMENT_CODE) {
    result = (MIN - positionMovement) * 100 / MIN;
  } else if (directionMovement == FORWARD_MOVEMENT_CODE || directionMovement == RIGHT_MOVEMENT_CODE) {
    result = (positionMovement - BASE_AXIS_VALUE - AXIS_INFELICITY) * 100 / (MAX - BASE_AXIS_VALUE - AXIS_INFELICITY);
  }
  return result;
}
