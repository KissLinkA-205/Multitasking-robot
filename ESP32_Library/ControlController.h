//
// Created by iange on 03.04.2022.
//

#ifndef CONTROLCONTROLLER_H
#define CONTROLCONTROLLER_H

#include "pch.h"
#include "Arduino.h"

class ControlController {
public:
    ControlController();
    ~ControlController();

    void turnOnLED();
    void turnOffLED();

    int getXPositionFromMovement();
    int getYPositionFromMovement();
    int getXPositionFromCameraMovement();
    int getYPositionFromCameraMovement();
};


#endif //CONTROLCONTROLLER_H
