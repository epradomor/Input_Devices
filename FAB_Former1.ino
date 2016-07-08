#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int currentMenuItem = 0;
int lastState = 0;
const int pinSensor = A5;   // pin del sensor de temperatura, va a la pata central del sensor
const int pinLed    = 2;      // pin para el led
const int buzzer    =3 ;    // pin para el buzzer
float temperatura ;        // variable para guardar la temperatura

  
void setup() 
{
lcd.begin(16, 2);
Serial.begin(9600); 
pinMode(pinLed,OUTPUT);
pinMode(buzzer,OUTPUT);
clearPrintTitle(); 
}

 
void loop() {
      temp();
       delay(150);
       mainMenu();
      }

void mainMenu()
{ 
  int state = 0;
  int x = analogRead (0);
  lcd.setCursor(0,0);
  if (x < 100) {
    //Right
  } else if (x < 200) {
   //Up
    state = 1;
  } else if (x 
  < 400){
   //Down
    state = 2;
  } else if (x < 600){
    //Left
  } else if (x < 800){
    //Select
    state = 3;
    
  }

  //If we a
  if (currentMenuItem < 0 || currentMenuItem >5) {
   currentMenuItem = 0; 
  }
   if (state != lastState) {
      if (state == 1) {
          currentMenuItem = currentMenuItem - 1; 
          displayMenu(currentMenuItem);
      } else if (state == 2) {
          currentMenuItem = currentMenuItem + 1;  
          displayMenu(currentMenuItem);
      } else if (state == 3) {
         seMenu(currentMenuItem); 
      }
          lastState = state;
   } 
  
  delay(1);

}

void clearPrintTitle() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  'FAB FORMER'");
  lcd.setCursor(0,1);
  lcd.print(" FABLAB PUEBLA");
}

void displayMenu(int x) {
     switch (x) {
      case 1:
        clearPrintTitle();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("TIPO DE MATERIAL");
        lcd.setCursor(0,1);
        lcd.print ("-> ESTIRENO");
        break;
      case 2:
        clearPrintTitle();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("TIPO DE MATERIAL");
        lcd.setCursor(0,1);
        lcd.print ("-> PET");
        break;
       case 3:
        clearPrintTitle();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("TIPO DE MATERIAL");
        lcd.setCursor(0,1);
        lcd.print ("-> EVA");
        break;
          }
}



void seMenu(int x) {
   switch (x) {
      case 1:
      while(x=1)
      {
        temp();
        clearPrintTitle();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print ("ESTIRENO");
        lcd.setCursor(0,1);
        lcd.print ("32 C   ");
        lcd.print (temperatura);
        if(temperatura > 32)
        {
        digitalWrite(2,LOW);
         digitalWrite(3,HIGH);
        }
        else
        {digitalWrite(2,HIGH);
         digitalWrite(3,LOW);}
        delay(500);
        
      }
        break;
     
      case 2:
      while(x=2)
      {
        temp();
        clearPrintTitle();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print ("PET");
        lcd.setCursor(0,1);
        lcd.print ("95-110 C  ");
        lcd.print (temperatura);
        if(temperatura > 100)
        {
        digitalWrite(2,LOW);
         digitalWrite(3,HIGH);
        }
        else
        {digitalWrite(2,HIGH);
         digitalWrite(3,LOW);}
        delay(500);
        
      }
        break;
        
       case 3:
       while(x=3)
       {
        temp();
        clearPrintTitle();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print ("EVA");
        lcd.setCursor(0,1);
        lcd.print ("120 C   ");
        lcd.print (temperatura);
        if(temperatura > 120)
        {
        digitalWrite(2,LOW);
         digitalWrite(3,HIGH);
        }
        else
        {digitalWrite(2,HIGH);
         digitalWrite(3,LOW);}
        delay(500);
        
      }
        break;
 
    }
}
//clase de la lectura para temperatura
void temp()
{
   int valorSensor = analogRead(pinSensor);  
       float milivolts = (valorSensor / 1023.0) * 5000;
       temperatura = milivolts / 10;
  
 }
