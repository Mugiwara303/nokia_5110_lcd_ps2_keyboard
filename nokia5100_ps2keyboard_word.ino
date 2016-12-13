#include <PS2Keyboard.h>
#include <Wire.h>
#include <LCD5110_Graph.h>
 
LCD5110 lcd(8, 9, 10, 12, 11);
extern unsigned char SmallFont[];

const int DataPin = 4;
const int IRQpin =  3;
char c;
int y = 0;
int x = 0;

PS2Keyboard keyboard;

void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin);
  lcd.InitLCD();
  lcd.setFont(SmallFont);
  lcd.print("Keyboard Test" , CENTER , 10);
  lcd.update();
  lcd.clrScr();
}

void loop() {

  if (keyboard.available()) {
    c = keyboard.read();
    char character[2];
    Serial.begin(9600);
    character[0] = c;
    character[1] = '\0';
    Serial.println("character aquals :");
    Serial.println(character);
    lcd.setFont(SmallFont);
    lcd.print(character, x, y);
    lcd.update();
    x = x + 6;
    if (x == 84 ) {
      y = y + 7; x = 0;
    }
  }
}


