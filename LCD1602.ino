#include <LiquidCrystal.h>

const int pinD[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int pinE = 10;
const int pinRS = 11;
const int buttom = 12;
const int pinBee = 13;
const int fButtomState = HIGH;

LiquidCrystal lcd(pinRS,pinE,2,3,4,5,6,7,8,9);

int beginOrNot = 1;
int times = 0;
int buttomTimes = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttom,INPUT);
  pinMode(pinBee,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("GOAL:");
  lcd.setCursor(0,1);
  lcd.print("SPEED:");
}

void loop() {
  // put your main code here, to run repeatedly:
  double redRead;
  redRead = analogRead(A0);//scroll or not
  if(redRead>700)
  {
    delayMicroseconds(50);
    if(redRead>700)
      times = (times+1)%20;
    delay(500);
  }
  lcd.setCursor(5,0);
  if(beginOrNot)
  {
    lcd.print(times);
    beeSing(100);
  }
  checkButtom();
}

void checkButtom(void)
{
  int buttomState;
  buttomState = digitalRead(buttom);
  Serial.println(buttomState);
  if(buttomState!=fButtomState)
  {
    delay(20);//avoid stumble
    if(buttomState!=fButtomState)
    {
      buttomTimes++;
      if(buttomTimes==2)
      {
        buttomTimes = 0;
        iniLCD();
        beeSing(1000);
      }
    }
  }
}

void iniLCD(void)
{
  lcd.clear();
  delay(500);
  lcd.print("GAME OVER!");
  delay(1000);
  lcd.clear();
  lcd.print("GAME START!!");
  delay(1000);
  lcd.clear();
   lcd.print("GOAL:");
  lcd.setCursor(0,1);
  lcd.print("SPEED:");
}
void beeSing(int seconds)
{
  digitalWrite(pinBee,LOW);
  delay(seconds);
  digitalWrite(pinBee,HIGH);
}

