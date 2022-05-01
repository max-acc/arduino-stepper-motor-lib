//Program for using a stepper motor (28-BYJ48) with a motor controller (L298N) and the "Stepper.h" library
//by Max Wenk
//
//https://github.com/max-acc
//
//This version is fully functional.

#include <Stepper.h>


const uint8_t stepsPerTurn = 200;  // Number depends on the motor -> number of steps per turn

// Initialising the two stepper motors
Stepper stepperMotor_0(stepsPerTurn, 2, 3, 5, 6);   // I don't know if PWM is required test it if you can!


// Initialising the stepper counters
uint8_t stepperCount_0 = 0;   // Number of steps the motors have already taken


// Setup
void setup() {
  Serial.begin(9600);   // Initialising the serial port
}

// --- Main starts here ------------------------------------------
void loop() {
  stepperForward();
  //stepperBackward();

  // Printing the number of the steps
  Serial.print("Stepper_0 steps: ");
  Serial.println(stepperCount_0);
  
  delay(500);   // Just to prevent unintended bugs
}

// Functions for turning the motors as intended
void stepperForward(){
  stepperMotor_0.step(1);
  stepperCount_0 += 1;
}

void stepperBackward(){
  stepperMotor_0.step(-1);
  stepperCount_0 += 1;
}
