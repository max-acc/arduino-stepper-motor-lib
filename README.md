# <p align="center"><b>Using a Stepper Motor</b></p>
The code below shows, how to use an unipolar Stepper Motor (28-BYJ48) with a Motor Controller (ULN2003).  
(-> the L298N cannot be used because it is designed for bipolar Stepper Motors)   
The [picture](../../blob/main/StepperCircuit.png "Circuit") shows how to connect the cables properly (you can ignore the second motor).  

There are three versions of the code:
* [using the already implemented Stepper.h library with one motor (a second one is commented out)](#Stepper-Motor-with-the-Stepper-library)
* [using the Stepper.h library as a foundation for simple object orientated programming (OOP)](#Stepper-Motor-with-OOP-and-without-a-library)
* [using the AccelStepper.h library with one motor (a second one is commented out)](#Stepper-Motor-with-the-AccelStepper-library)
</br>
Important Annotation: It is not necessary to connect a separate battery to the Stepper Motor Controller (if you use the 5V version of the Stepper Motor), but it is recommended to use one (to protect the electronics). The Arduino is able to output 5V but it may not work flawlessly.
</br>  
</br>
</br>

### <p align="left">Stepper Motor with the Stepper library</p>
The [Stepper.h library](https://github.com/arduino-libraries/Stepper) is already implemented in the Arduino IDE. To implement the library, go to ```Sketch``` -> ```Include Library``` and search for ```Stepper``` or just write ```#include <Stepper.h>``` to include the library.  
The [provided program](../../tree/main/simple-stepper-control) will move the Stepper(s) as they are might be intended. The program is pretty self-explanatory (there are a lot of comments).  
</br>

### <p align="left">Stepper Motor with OOP and without a library</p>
The [program](../../tree/main/simple-stepper-contorl-oop) is using the [Stepper.h library](https://github.com/arduino-libraries/Stepper) as a foundation for [object orientated programming](https://en.wikipedia.org/wiki/Object-oriented_programming). OOP is an important programming concept which is widely spread (many of the most widly used programming languages support it).  
The [provided program](../../tree/main/simple-stepper-contorl-oop) is much more space efficient because some funtions of the Stepper.h library, which are for other Stepper Motors, are missing (because they are not needed for the 28-BYJ48 Stepper Motor).  
</br>
At first, a class called ```StepperMotor``` is being created. After that, some private variables for later usage are being initialised. Those variables are accessable inside the class, so you can't call them (it is kind of code protection). Only the class itself can call them. After that. some public funtions are initialised. The first function is a ```constructer``` because it has the same name as the class. The constructor is called every time when a new object is being created. This explicit constructor declares the previous initialised variables. The other functions just apply logic for moving a Stepper Motor. The rest of the program is almost the same as in the first [program](../../tree/main/simple-stepper-control). The only difference is that ```Stepper``` is replaced by ```StepperMotor```, because we changed the class name.  
Understanding this code (the Stepper.h lib) leads to more control over the Stepper Motor.
</br>

### <p align="left">Stepper Motor with the AccelStepper library</p>

https://github.com/waspinator/AccelStepper

[program](../../tree/main/stepper-motor)

Important Annotation: The Stepper Motor is designed for only 5V, otherwise it will get pretty hot and may brake. 
</br>  
</br>

## Arduino NANO
Since the Arduino NANO has a different chip built-in, you have to compile the program in another way which is pretty straight forward. Nevertheless it won't work if you use the standard bootloader.  
To change the board, go to ```Tools``` -> ```Board``` and change it to ```Arduino Nano```.  
After that, go to ```Tools``` -> ```Processor``` and change it to ```ATmega328P (Old Bootloader)```.  
</br>
It is recommended to change the bootloader to the standard one if you are working on other projects because the change of the booloader could lead to problems with other programs.
</br>  

## Scripts
In the [scripts folder](../../tree/main/scripts) are some scripts explaining in detail how to use the Stpper lib. Those scripts are only in German.
</br>  

## Sources
* https://coeleveld.com/arduino-stepper-l298n/
* https://forum.arduino.cc/t/was-haltet-ihr-von-l298n-stepper-motor-driver/251568/4
* https://www.reddit.com/r/arduino/comments/ie4koa/driving_28byj48_stepper_motor_with_l298n_driver/
* https://rjdlee.com/arduino-wemos-with-l298n-controller-and-28byj-48-stepper-motor/
* https://imgur.com/cRB2d5p
* https://components101.com/motors/28byj-48-stepper-motor  
All Links were valid on May 1st 2022.

[:arrow_up:Back to top](#Using-a-stepper-motor)
