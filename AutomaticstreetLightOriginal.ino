#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 int led_Pin_7 = 7;  // Define the LED pin
 int LDR_Pin_A0 = A0;
void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Print a message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("AUTOMATED LIGHT");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("GROUP 5 PROJECT");
  delay(500);
  lcd.clear();

  Serial.begin(9600);
  
  pinMode(led_Pin_7, OUTPUT);
}

void loop() {
  int a = analogRead(A0);
  Serial.println(a);

  if (a < 220) {
    lcd.setCursor(0, 1);
    lcd.print("NIGHT"); 
    digitalWrite(led_Pin_7, HIGH);
    delay(500);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("DAY");
    digitalWrite(led_Pin_7, LOW);
    delay(500);
  }
}