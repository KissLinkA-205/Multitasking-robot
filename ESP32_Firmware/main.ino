#include <ESPManager.h>

ESPManager manager = ESPManager();


void setup() {
  manager.begin();
}

void loop() {
  manager.handle();
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
