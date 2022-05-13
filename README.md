# <p align="center"><b>Using a Stepper Motor</b></p>
The code below shows, how to use a Stepper Motor (28-BYJ48) with a motor controller (UN2003).  
The [picture](../../circuit.png "Circuit") shows how to connect the cables properly (you can ignore the second motor).  

There are three versions of the code:
* [using the already implemented Stepper.h library with one motor (a second one is commented out)](#Stepper-Motor-with-the-Stepper-library)
* [using the Stepper.h library as a foundation for simple object orientated programming (OOP)](#Stepper-Motor-with-OOP-and-without-a-library))
* [using the AccelStepper.h library with one motor (a second one is commented out)](#Stepper-Motor-with-the-AccelStepper-library)
</br>
Important Annotation: It is not necessary to connect a separate battery to the Stepper Motor controller (if you use the 5V version of the Stepper Motor), but it is recommended to use it (to protect the electronics). The Arduino is able to output 5V but it may not work flawlessly.
</br>  
</br>
</br>

### <p align="left">Stepper Motor with the Stepper library</p>
The [Stepper.h library](https://github.com/arduino-libraries/Stepper) is already implemented in the Arduino IDE. To implement the library, go to ```Sketch``` -> ```Include Library``` and search for ```Stepper``` or just write ```#include <Stepper.h>``` to include the library.  
The [provided program](../../tree/main/simple-stepper-control) will move the Stepper(s) as they are might be intended. The program is pretty self-explanatory (there are a lot of comments).  
</br>

### <p align="left">Stepper Motor with OOP and without a library</p>

[program](../../tree/main/simple-stepper-contorl-oop)
</br>

### <p align="left">Stepper Motor with the AccelStepper library</p>

https://github.com/waspinator/AccelStepper

[program](../../tree/main/stepper-motor)

Important Annotation: The Stepper Motor is designed for only 5V, otherwise it will get pretty hot and may brake. 

## Sources
* https://coeleveld.com/arduino-stepper-l298n/
* https://forum.arduino.cc/t/was-haltet-ihr-von-l298n-stepper-motor-driver/251568/4
* https://www.reddit.com/r/arduino/comments/ie4koa/driving_28byj48_stepper_motor_with_l298n_driver/
* https://rjdlee.com/arduino-wemos-with-l298n-controller-and-28byj-48-stepper-motor/
* https://imgur.com/cRB2d5p
* https://components101.com/motors/28byj-48-stepper-motor  
All Links were valid on May 1st 2022.

[:arrow_up:Back to top](#Using-a-stepper-motor)
