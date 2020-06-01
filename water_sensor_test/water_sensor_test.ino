/*
  
water_sensor_test.ino
  The legge program and the analogical value of the sensor
  0 if your sensor is asciutto

  Sono utilizzati i seguenti pin
  Pin +5V         -> Alimentazione sensore
  Pin GND         -> GND sensore /led
  Pin Digitale 2  -> Led Rosso
  Pin Digitale 3  -> led Verde
  Pin Analogico 0 -> Segnale sensore
*/
int sensore   = 0; // Analog pin to be attached to the sensor
int rosso     = 2; //Pin to which the red led is connected
int verde     = 3; //Pin to which the green led is connected
int soglia    = 200; // Set threshold value

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  pinMode (rosso, OUTPUT);    // Set pin 2 red string as output.
  pinMode (verde, OUTPUT);    // Set pin 3 lede green as output.
  digitalWrite(verde, HIGH);  //Turns on green led
}

void loop() {
  // Reading the sensor value
  int lettura = analogRead(sensore);
  // Reading of the value read
  Serial.println(lettura);
  if (lettura >= soglia) {
    digitalWrite(verde, LOW);   // Turn off green led
    digitalWrite(rosso, HIGH);  // Turns on the red LED
  }
  else {
    digitalWrite(verde, HIGH);  // Turns on green led
    digitalWrite(rosso, LOW);   // Turn off red led
  }
  // Pause between readings
  delay(100);
}
