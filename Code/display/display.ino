#include <LiquidCrystal_PCF8574.h>
#include <Wire.h> 
LiquidCrystal_PCF8574 lcd(0x27);

void setup()
{
  lcd.begin(16, 2);                     // Инициализация дисплея  
  lcd.setBacklight(255);                 // Подключение подсветки
  lcd.clear();              // Установка курсора в начало первой строки
  lcd.print("Silkwarms");       // Набор текста на первой строке
  lcd.setCursor(0,1);              // Установка курсора в начало второй строки
  lcd.print("Winding_coils");       // Набор текста на второй строке
}
void loop()
{
}
