/*
* Simple RC Motor Dyno
* Author - Josiah Bailey 
*/

//Includes
#include <Servo.h>
#include <stdio.h>

#include "cli.h"
#include "serial.h"

#include <SPI.h>
#include "AS5040.h"

//Defines
#define neutral 0
#define START_CMD 'g'
#define STOP_CMD 's' 

/* Pins definitions */
#define CSpin 10
#define MOSIpin 11
#define MISOpin 12
#define CLKpin 13

//Working Data 
int controlData = 0;

// create servo object to control a servo
Servo myservo;  

/* Command Line interface */
ttcli cli;

/* Instance AS5040 magnetic position sensor */
AS5040Class AS5040(CSpin, CLKpin, MISOpin, MOSIpin);

void setup() {
    // put your setup code here, to run once:

    /* Initialize Serial */
    serial_init();

    myservo.attach(9);       // attaches the servo on pin 9 to the servo object

    /* set the CSpin as an output */
    pinMode(CSpin, OUTPUT);

    SPI.begin();
    AS5040.begin(&SPI, SPISettings(AS5040_CLKAREAD, MSBFIRST,SPI_MODE1));

    /* Send Start RARW!! */
    cli.begin();
}

void loop() {
    // put your main code here, to run repeatedly:

    /* Command Line Interfase runner */
    cli.run();  

    Serial.println(AS5040.readAbsolutePosition());

    delay(1000);

    /*
       if (controlData == START_CMD)
       {
       myservo.write(180);
       Serial.print("Servo: ");
       Serial.println(myservo.read());
       }
       else if (controlData == STOP_CMD)
       {
       myservo.write(95);
       Serial.print("Servo: ");
       Serial.println(myservo.read());
       }
     */

}

// 
// End of file.
//
