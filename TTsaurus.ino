/*
* Simple RC Motor Dyno
* Author - Josiah Bailey 
*/

//Includes
#include <Servo.h>
#include <stdio.h>

#include "cli.h"

char rawr[5] = {'r','a','r','w'};
//Defines
#define neutral 0
#define start "rawr"
#define START_CMD 'g'
#define STOP_CMD 's' 



//Working Data 
int controlData = 0;

// create servo object to control a servo
Servo myservo;  

/* Command Line interface */
ttcli cli;

void setup() {
  // put your setup code here, to run once:

  /* Initialize Serial */
  Serial.begin(9600); while(!Serial){;} /* Wait serial connection TODO: add a loop break */

  /* Send Start RARW!! */
  Serial.println(rawr + '!!!');

  myservo.attach(9);       // attaches the servo on pin 9 to the servo object

  cli.menue();

}

void loop() {
  // put your main code here, to run repeatedly:

    /* Command Line Interfase runner */
    cli.run();  

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
