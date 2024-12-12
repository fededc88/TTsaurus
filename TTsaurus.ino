/*
* Simple RC Motor Dyno
* Author - Josiah Bailey 
*/

//Includes
#include <Servo.h>
#include <stdio.h>

//Defines
#define neutral 0
#define start 49
#define stop 50 

//Working Data 
int controlData = 0;

// create servo object to control a servo
Servo myservo;  

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  myservo.attach(9);       // attaches the servo on pin 9 to the servo object
  Serial.println(start);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Wait for a "Start" command
  controlData = Serial.read();
 
  if (controlData == start)
  {
    myservo.write(180);
  }
  else if (controlData == stop)
  {
    myservo.write(95);
  }
  else
  {
    Serial.println(controlData);
  }

  Serial.flush();
  delay(1000);
  //Serial.println(controlData);

  //Blink
}
