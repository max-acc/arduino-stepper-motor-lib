//Stepper OOP
//by Max Wenk
//
//https://github.com/max-acc
//
//Using the Stepper.h library as a foundation for simple object orientated programming (OOP)


// Stepper motor class for a four pin Steppermotor
class StepperMotor {
  private:
    //void stepMotor(int this_step);

    int direction;            // Direction of rotation
    unsigned long step_delay; // delay between steps, in ms, based on speed
    int numberOfSteps;        // total number of steps this motor can take
    int pinCount;             // how many pins are in use.
    int step_number;          // which step the motor is on

    // motor pin numbers:
    int motorPin1;
    int motorPin2;
    int motorPin3;
    int motorPin4;

    unsigned long last_step_time; //Timestamp in us of when the last step was taken

  
  public:
    // Constructor for declararing the pins
    StepperMotor(int numberOfSteps, int motorPin1, int motorPin2, int motorPin3, int motorPin4) {
      this->numberOfSteps = 0;    // which step the motor is on
      this->direction = 0;      // motor direction
      this->last_step_time = 0; // time stamp in us of the last step taken
      this->numberOfSteps = numberOfSteps; // total number of steps for this motor

      // Arduino pins for the motor control connection:
      this->motorPin1 = motorPin1;
      this->motorPin2 = motorPin2;
      this->motorPin3 = motorPin3;
      this->motorPin4 = motorPin4;

      // setup the pins on the microcontroller:
      pinMode(this->motorPin1, OUTPUT);
      pinMode(this->motorPin2, OUTPUT);
      pinMode(this->motorPin3, OUTPUT);
      pinMode(this->motorPin4, OUTPUT);

      // pinCount is used by the stepMotor() method:
      this->pinCount = 4;
    }

    void setTheSpeed(long whatSpeed) {
      this->step_delay = 60L * 1000L * 1000L / this->numberOfSteps / whatSpeed;
    }

    void makeAStep(int steps_to_move) {
      int steps_left = abs(steps_to_move);  // how many steps to take

      // determine direction based on whether steps_to_mode is + or -:
      if (steps_to_move > 0) {
        this->direction = 1;
      }
      if (steps_to_move < 0) {
        this->direction = 0;
      }


      // decrement the number of steps, moving one step each time:
      while (steps_left > 0) {
        unsigned long now = micros();
        // move only if the appropriate delay has passed:
        if (now - this->last_step_time >= this->step_delay) {
          // get the timeStamp of when you stepped:
          this->last_step_time = now;
          // increment or decrement the step number,
          // depending on direction:
          if (this->direction == 1) {
            this->step_number++;
            if (this->step_number == this->numberOfSteps) {
              this->step_number = 0;
            }
          }
          else {
            if (this->step_number == 0) {
              this->step_number = this->numberOfSteps;
            }
            this->step_number--;
          }
          // decrement the steps left:
          steps_left--;
          // step the motor to step number 0, 1, ..., {3 or 10}
          if (this->pinCount == 5)
            stepMotor(this->step_number % 10);
          else
            stepMotor(this->step_number % 4);
        }
      }
    }

    void stepMotor(int thisStep) {
      switch (thisStep) {
        case 0:  // 1010
          digitalWrite(motorPin1, HIGH);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          break;
        case 1:  // 0110
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, HIGH);
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          break;
        case 2:  //0101
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, HIGH);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, HIGH);
          break;
        case 3:  //1001
          digitalWrite(motorPin1, HIGH);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, HIGH);
          break;
      }
    }
};


/* Functions for the stepperMotor class
 * StepperMotor ->  Stepper
 * setTheSpeed  ->  setSpeed
 * makeAStep    ->  step
 * stepMotor    ->  stepMotor
 */


const uint8_t stepsPerTurn = 200;  //Number depends on the motor -> number of steps per turn

//Initialising the two stepper motors
StepperMotor stepperMotor_0(stepsPerTurn, 2, 4, 3, 5);   //PWM Pins are not required, but the order of the Pins is relevant
//StepperMotor stepperMotor_1(stepsPerTurn, 8, 10, 9, 11);


//Initialising the stepper counters
uint8_t stepperCount_0 = 0;   //Number of steps the motors have already taken
//uint8_t stepperCount_1 = 0;


//Setup
void setup() {
  Serial.begin(9600);   //Initialising the serial port
  stepperCount_0.setSpeed(50);  //Setting the Speed of the motors (can be adjusted, but may won't work)
  //stepperMotor_1.setSpeed(50);
}

//--- Main starts here ------------------------------------------
void loop() {
  steppersForward();    //Moves both stepper motors
  //steppersBackward();
  //steppersLeft();
  //steppersRight();

  //Printing the number of the steps
  Serial.print("Stepper_0 steps: ");
  Serial.println(stepperCount_0);
  //Serial.print("Stepper_1 steps: ");
  //Serial.println(stepperCount_1);
  
  delay(500);   //Just to prevent unintended bugs, can be shorten
}

//Functions for turning the motors as intended -> one turns forward, the other one backward
void steppersForward(){
  stepperMotor_0.makeAStep(1);
  stepperCount_0 += 1;
  stepperMotor_1.makeAStep(-1);  //Has to be inverted since the motor is upside down ig
  stepperCount_1 += 1;
}

//Same as the function above, just inverted
void steppersBackward(){
  stepperMotor_0.makeAStep(-1);
  stepperCount_0 += 1;
  stepperMotor_1.makeAStep(1);
  stepperCount_1 += 1;
}

//Simple logic applied to move the steppers
void steppersLeft(){
  stepperMotor_0.makeAStep(-1);
  stepperCount_0 += 1;
  stepperMotor_1.makeAStep(-1);
  stepperCount_1 += 1;
}
void steppersRight(){
  stepperMotor_0.makeAStep(1);
  stepperCount_0 += 1;
  stepperMotor_1.makeAStep(1);
  stepperCount_1 += 1;
}
