//
// Created by Anzhalika Dziarkach on 03.04.2022.
//

#ifndef CONTROLCONTROLLER_H
#define CONTROLCONTROLLER_H

#include "pch.h"
#include "Arduino.h"

#define BASE_AXIS_VALUE 1800
#define AXIS_INFELICITY 350
#define MIN_AXIS_VALUE 1500
#define MAX_AXIS_VALUE 4100

const char FORWARD_MOVEMENT_CODE = 'f';
const char BACK_MOVEMENT_CODE = 'b';
const char RIGHT_MOVEMENT_CODE = 'r';
const char LEFT_MOVEMENT_CODE = 'l';
const char STOP_MOVEMENT_CODE = 's';

const String FORWARD_MOVEMENT = "FORWARD";
const String BACK_MOVEMENT = "BACK";
const String RIGHT_MOVEMENT = "RIGHT";
const String LEFT_MOVEMENT = "LEFT";
const String STOP_MOVEMENT = "STOP";

class ControlController {
public:
    ControlController();
    ~ControlController();

    void turnOnLED();
    void turnOffLED();

    void turnOnSound();
    void turnOffSound();

    void turnOnVibro();
    void turnOffVibro();

    int getXPositionFromMovementJoystick();
    int getYPositionFromMovementJoystick();
    bool isMovementButtonPressed();

    int getXPositionFromCameraJoystick();
    int getYPositionFromCameraJoystick();
    bool isCameraButtonPressed();

    String getDirectionMovement(int x, int y);
    char getDirectionMovementCode(int x, int y);
    int getSpeed(int x, int y);
};


#endif //CONTROLCONTROLLER_H
