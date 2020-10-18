#include <Arduino.h>
#include "TinyStepper_28BYJ_48.h"

TinyStepper_28BYJ_48 stepperL;
TinyStepper_28BYJ_48 stepperR;

void setup() {
    stepperL.connectToPins(D1, D2, D3, D4);
    stepperR.connectToPins(D5, D6, D7, D8);
    stepperL.setSpeedInStepsPerSecond(300);
    stepperR.setSpeedInStepsPerSecond(300);

}

void loop() {
    stepperL.setupMoveInSteps(500);
    stepperR.setupMoveInSteps(500);
    while(!stepperL.motionComplete() || !stepperR.motionComplete()) {
        stepperL.processMovement();
        stepperR.processMovement();
    }
}
