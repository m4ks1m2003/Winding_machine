#include <LiquidCrystal_PCF8574.h>
#include <Wire.h> 
LiquidCrystal_PCF8574 lcd(0x27);

// 1 двигатель
const int STEP_PIN1=5;
const int DIR_PIN1=4;
// 2 двигатель
const int STEP_PIN2=3;
const int DIR_PIN2=2;

void setup() {

  pinMode(STEP_PIN1, OUTPUT);
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(STEP_PIN2, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);

  digitalWrite(STEP_PIN1, 1);
  digitalWrite(DIR_PIN1, 0);
  digitalWrite(STEP_PIN2, 1);
  digitalWrite(DIR_PIN2, 0);
  
  Serial.begin(9600);
  lcd.begin(16, 2);                     // Инициализация дисплея  
  lcd.setBacklight(255);                 // Подключение подсветки
  lcd.clear();              // Установка курсора в начало первой строки
  lcd.print("Made by");       // Набор текста на первой строке
  lcd.setCursor(0,1);              // Установка курсора в начало второй строки
  lcd.print("Silkwarms");       // Набор текста на второй строке
}

int TURNS = 0;

void loop() { 
  lcd.clear();
  lcd.print("Turns?");
  TURNS = Serial.read();
  Winding (10,TURNS); 
}

void Winding (int diam, int turns) {
  lcd.clear();              
  lcd.print("Please, wait..."); 
  delay(1000);      
  int DELAY_STEPS1=10;
  int DELAY_STEPS2=20; 
  int STEP_ROUND=200;

  lcd.clear();              
  lcd.print("Turns: "); 
  lcd.setCursor(11,0);              
  lcd.print("/");
  lcd.setCursor(13,0);              
  lcd.print(turns);

  digitalWrite(DIR_PIN1, HIGH);
  digitalWrite(DIR_PIN2, LOW);
  
  for(int turn_now = 1; turn_now < turns + 1; turn_now++) {   
    lcd.setCursor(8,0);              
    lcd.print(turn_now);
    Serial.print(turn_now, "/", turns);
    for(int i = 0; i < STEP_ROUND; i++) {
      
      digitalWrite(STEP_PIN1, HIGH);
      delay(DELAY_STEPS1);
      digitalWrite(STEP_PIN1, LOW);
      delay(DELAY_STEPS1);
    
      digitalWrite(STEP_PIN2, HIGH);
      delay(DELAY_STEPS2);
      digitalWrite(STEP_PIN2, LOW);
      delay(DELAY_STEPS2);
      
     
    }
    
  }

}
