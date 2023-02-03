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


