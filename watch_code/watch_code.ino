//Relog to control planting time

//Importar Librerías para el lcd y el teclado
#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

//Variables utilizadas
int h, m ,s =0;
unsigned long tiempoPas=0;
int segundo=1000;
boolean listo=false;

//Config del Teclado
const byte filas=4;
const byte colum=4;

char botones[filas][colum]={
  {
    '1','2','3','A'  }
  ,
  {
    '4','5','6','B'  }
  ,
  {
    '7','8','9','C'  }
  ,
  {
    '*','0','#','D'  }
};

byte pinesFila[filas]={
  0,1,2,3};
byte pinesColu[colum]={
  4,5,6,7};
Keypad teclado=Keypad( makeKeymap(botones),pinesFila,pinesColu,filas,colum );

int numTeclado()
{
  int num = 0;
  char key = teclado.getKey();
  while(key != '#')
  {
    switch (key)
    {
    case NO_KEY:
      break;
    case '0': case '1':  case '2': case '3': case '4':
    case '5': case '6':  case '7': case '8': case '9':
      lcd.print(key);
      num = num * 10 + (key - '0');
      break;
    case '*':
      num = 0;
      lcd.clear();
      break;
    }
    key = teclado.getKey();
  }
  return num;
}


void reloj(){
  s++;
  if(s>59){
    s=0;
    m++;
    if(m>59){
      m=0;
      h++;
      if(h<23){
        h=0;
      }
    }
  }
}


String formato(int num){
  String resultado="";
  if(num<10)
    resultado="0"+String(num);
  else
    resultado=String(num);
  return resultado;
}


void configurar(){
  lcd.setCursor(0,0);
  lcd.print("Hora:");
  lcd.setCursor(0,1);
  h=numTeclado();
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Minutos:");
  lcd.setCursor(0,1);
  m=numTeclado();
  lcd.clear();
  listo=true;
}


void setup() {
  lcd.begin(16,2);
}

void loop(){
  unsigned long tiempo=millis();
  if(listo){
    if(tiempo - tiempoPas > segundo) {
      tiempoPas = tiempo;
      reloj();
    }
    String laHora = "--- "+formato(h)+":"+formato(m)+":"+formato(s)+" ---";
    lcd.setCursor(0,0);
    lcd.print(laHora);
  }
  else{
    configurar();
  }
}
