//Automated irrigation system and temperature control.


int Bomba=2;                                   //we declare to which pin it belongs
int Selenoide1=3;                              //every thing
int Selenoide2=5;
int ctrlBomba = 1;                             // to control that the pump turns on once
int Humidity1 = analogRead (A0);              //we declare sensor one at input A0 
int Humidity2 = analogRead (A1);              //we declare sensor two at input A1
    String a;                                   //pump reading
    String b;                                   //reading from the selenoid one
    String c;                                   //reading from selenoid two


//temperature sensor.

float tempC; // Variable to store the value obtained from the sensor (0 to 1023)
int pinLM35 = 0; // Sensor input pin variable (A3)



void setup()
{
    Serial.begin(9600);                       // we open the serial port
    pinMode(Bomba,OUTPUT);                    
    pinMode(Selenoide1,OUTPUT);
    pinMode(Selenoide2,OUTPUT);
    
    // We change the reference of the analog inputs (temperature sensor.)
  analogReference(INTERNAL);

  
}

void datosapython()
{
                                                // we convert the humidity data to pass it to python
    String humiditi1 = "humedad uno = " + (String)Humidity1;
    String humiditi2 = "humedad dos = " + (String)Humidity2;

                                             // we send the data to python

    Serial.println(humiditi1);
    Serial.println(humiditi2);
    Serial.println(a);
    Serial.println(b);
    Serial.println(c);
}

//the relays turn on at Low and turn off at HIGH

void loop()
{

 // as long as humidity sensor one or humidity sensor two need water.
    while (Humidity1 >= 400 or Humidity2 >= 400){
                                                 
        if (ctrlBomba == 0 ){                       // the pump is turned on
          digitalWrite(Bomba,LOW);                  // with this if we control that the pump turns on only once
          a=("ONB");                                // Pump on.
          ctrlBomba = 1;                              
          }                           
                                                    // if both sensors need water
        else if ( Humidity1 > 400 and Humidity2 > 400){                                                
        digitalWrite(Selenoide1,LOW);
        b=("ONS1");                                 // Selenoid one open
        digitalWrite(Selenoide2,LOW);
        c=("ONS2");                                 // Selenoid two open
                                                    // if the number one humidity sensor needs water
        }                                           //and humidity sensor number two doesn't need
        else if ( Humidity1 > 400 and Humidity2 < 400){                                                
        digitalWrite(Selenoide1,LOW);
        b=("ONS1");                                 // Selenoid an open
        digitalWrite(Selenoide2,HIGH);
        c=("OFFS2");                             // Selenoid two closed
                                                 // if humidity sensor number two needs water
        }                                         //and the number one humidity sensor doesn't need
        else if(Humidity2 > 400 and Humidity1 < 400){
        digitalWrite(Selenoide2,LOW);                                                                 
        c=("ONS2");                              // Selenoid two open
        digitalWrite(Selenoide1,HIGH);
        b=("OFFS1");                            // Selenoid one closed
        }

        datosapython();                         //we send the data to python
    }
//If humidity sensor one and humidity sensor two do not need water
    if ( Humidity1 <= 400 and Humidity2 <= 400)
    {
                                                // turn off the pump
        digitalWrite(Bomba,HIGH);
        a=("OFFB");                             // Pump off
                                                // wait a while for the remaining water
                                                //in the hose is fenced
        delay(2000);
                                                // the first selenoid closes
        digitalWrite(Selenoide1,HIGH);
        b=("OFFS1");                            // Selenoid one closed
                                                // the second selenoid closes
        digitalWrite(Selenoide2,HIGH);
        c=("OFFS2");                           // Selenoid two closed
 
    }
    
        datosapython();                        // we send the data to python
                                               // time between cycles


 //temperature sensor.
  
  tempC = analogRead(pinLM35); 
   
 // We calculate the temperature with the formula
  tempC = (1.1 * tempC * 100.0)/1024.0; 
 
 
  Serial.print(tempC);

  Serial.print("\n");
  
  delay(3000);

  
}







 

 
