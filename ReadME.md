
# Blink an LED using Arduino FreeRTOS

One of the most important components of today's embedded systems is the RTOS also known as Real-Time Operating System, which is responsible for everything from task scheduling to performing applications. RTOS is designed to provide a predictable execution mode. When the processing must meet the time limit of the system, RTOS is used. Therefore, compared with GPOS (General Purpose Operating System), RTOS is usually light in weight and small in size, and generally only provides functions required to run specific types of applications on specific hardware. FreeRTOS is a class of RTOS that is designed to be small enough to run on a microcontroller – although its use is not limited to microcontroller applications. FreeRTOS includes a kernel and a growing set of software libraries suitable for use across industry sectors and applications.





## Components Used

### Hardware

1. Arduino NANO
2. LEDs
3. Wires & Breadboard
4. Power Supply 

### Software

1. VS Code (Arduino IDE Extension)



## Schematic 

<img src="https://firebasestorage.googleapis.com/v0/b/common-project-63634.appspot.com/o/Blink%20an%20LED%20using%20Arduino%20FreeRTOS%2Fsch1.PNG?alt=media&token=44e77187-535c-468e-9613-f95508481c51"></img>

## Result

<img src="https://firebasestorage.googleapis.com/v0/b/common-project-63634.appspot.com/o/Blink%20an%20LED%20using%20Arduino%20FreeRTOS%2Fim1.jpg?alt=media&token=b275880a-3b6a-46ac-91b4-b3c9fd29d2a3"></img>

<img src="https://firebasestorage.googleapis.com/v0/b/common-project-63634.appspot.com/o/Blink%20an%20LED%20using%20Arduino%20FreeRTOS%2Fimg3.jpg?alt=media&token=1991c694-b8a1-4aaa-a39e-5031945957fb"></img>

<img src="https://firebasestorage.googleapis.com/v0/b/common-project-63634.appspot.com/o/Blink%20an%20LED%20using%20Arduino%20FreeRTOS%2Fimg2.jpg?alt=media&token=1685bcfa-e170-409d-bad4-8e595cce0978"></img>

## Code 

```javascript
/*
Author: Mohd Aman Ansari
embed
https://embed.org.in
*/
#include <Arduino_FreeRTOS.h>
#define RED    6    //PIN of LED Red
#define GREEN 7    //PIN of LED Green
#define WHITE   8    //PIN of LED White


// the setup function runs once when you press reset or power the board
void setup()

{
     // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    // Now set up two tasks to run independently.
    xTaskCreate(redLedControllerTask, "RED LED Task", 128, NULL, 1, NULL);
    xTaskCreate(greenLedControllerTask, "GREEN LED Task", 128, NULL, 1, NULL);
    xTaskCreate(whiteLedControllerTask, "WHITE LED Task", 128, NULL, 1, NULL);
}

// Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.


void loop()

{
 // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/


void redLedControllerTask(void *pvParameters)   // This is a task.
{
    // initialize digital LED "RED" on pin 6 as an output.
    pinMode(RED, OUTPUT);
    while (1)
    {
        digitalWrite(RED, digitalRead(RED)^1);   // turn the LED on (HIGH is the voltage level)
        delay(100);    // wait for 1ms
    }
    

}

void greenLedControllerTask(void *pvParameters)   // This is a task.
{
    // initialize digital LED "GREEN" on pin 7 as an output.
    pinMode(GREEN, OUTPUT);
    while (1)
    {
        digitalWrite(GREEN, digitalRead(GREEN)^1);    // turn the LED on (HIGH is the voltage level)
        delay(100);      // wait for 1ms
    }
    

}
void whiteLedControllerTask(void *pvParameters)    // This is a task.
{   
    // initialize digital LED "WHITE" on pin 8 as an output.
    pinMode(WHITE, OUTPUT);
    while (1)
    {
        digitalWrite(WHITE, digitalRead(WHITE)^1);     // turn the LED on (HIGH is the voltage level)
        delay(100);    // wait for 1ms
    }
    

}

