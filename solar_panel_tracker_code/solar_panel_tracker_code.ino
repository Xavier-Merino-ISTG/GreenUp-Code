/* 

We will use LDR to detect light and rotate the servo motors 
connected to the circuit, to move the direction of the solar
panel towards the light source.
*/

#include <Servo.h> // including the servo motor library
Servo sg90; // initializing a variable for the servo called sg90
int initial_position = 90; // Declaring the starting position at 90
int LDR1 = A0; // Pin to which LDR is connected
int LDR2 = A1; // Pin to which LDR is connected
int error = 5; // initialization variable for error
int servopin = 9;
configuración nula () 
{ 

  sg90.attach (servopina); // attach the servo on pin 9
  pinMode (LDR1, INPUT); // Make the LDR pin as input
  pinMode (LDR2, INPUT);
  sg90.write (posición_inicial); // Move the servo to 90 degrees
  retraso (2000); // giving a delay of 2 seconds
}  
 
void loop () 
{ 
  int R1 = analogRead (LDR1); // LDR reading value 1
  int R2 = analogRead (LDR2); // LDR 2 read value
  int diff1 = abs (R1 - R2); // Calculation of the difference between the LDRs
  int diff2 = abs (R2 - R1);
  
  if ((diff1 <= error) || (diff2 <= error)) {
    // if the difference is below the error then do nothing

  } más {    
    if (R1> R2)
    {
      posición_inicial = - posición_inicial; //Move the servo to 0 degrees
    }
    if (R1 <R2) 
    {
      initial_position = ++ initial_position; // Move the servo 180 degrees
    }
  }
  sg90.write (initial_position); // write the position in servo
  delay (100);
}
