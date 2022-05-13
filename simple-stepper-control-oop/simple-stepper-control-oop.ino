//Stepper
//by Max Wenk
//
//https://github.com/max-acc
//
//Using the already implemented Stepper.h library with one motor (a second one is commented out) -> Application could be a care (one motor is mirrored, cause its turned by 180deg)


#include <Stepper.h>

const uint8_t stepsPerTurn = 200;  // Number depends on the motor -> number of steps per turn (can be adjusted, but may won't work)

// Initialising the two stepper motors
Stepper stepperMotor_0(stepsPerTurn, 2, 4, 3, 5);   // PWM Pins are not required, but the order of the Pins is relevant
//Stepper stepperMotor_1(stepsPerTurn, 8, 10, 9, 11);


// Initialising the stepper counters
uint8_t stepperCount_0 = 0;   // Number of steps the motors have already taken
//uint8_t stepperCount_1 = 0;



// Setup
void setup() {
  Serial.begin(9600);   // Initialising the serial port
  stepperCount_0.setSpeed(50);  //Setting the Speed of the motors (can be adjusted, but may won't work)
  //stepperMotor_1.setSpeed(50);
}

// --- Main starts here ------------------------------------------
void loop() {
  steppersForward();    //Moves both stepper motors
  //steppersBackward();
  //steppersLeft();
  //steppersRight();

  // Printing the number of the steps
  Serial.print("Stepper_0 steps: ");
  Serial.println(stepperCount_0);
  //Serial.print("Stepper_1 steps: ");
  //Serial.println(stepperCount_1);
  
  delay(500);   // Just to prevent unintended bugs, can be shorten
}

// Functions for turning the motors as intended -> one turns forward, the other one backward
void steppersForward(){
  stepperMotor_0.step(1);
  stepperCount_0 += 1;
  //stepperMotor_1.step(stepsPerTurn);  // Has to be inverted cause the motor is upside down ig
  //stepperCount_1 += 1;
}

//Same as the function above, just inverted
void steppersBackward(){
  stepperMotor_0.step(-1);
  stepperCount_0 += 1;
  //stepperMotor_1.step(1);
  //stepperCount_1 += 1;
}

//Simple logic applied to move the steppers
void steppersLeft(){
  stepperMotor_0.step(-1);
  stepperCount_0 += 1;
  //stepperMotor_1.step(-1);
  //stepperCount_1 += 1;
}
void steppersRight(){
  stepperMotor_0.step(1);
  stepperCount_0 += 1;
  //stepperMotor_1.step(1);
  //stepperCount_1 += 1;
}
