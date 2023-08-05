#include <DS3231.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

DS3231  rtc(SDA, SCL);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Time  t;
String mon, day;
void setup()
{
  lcd.begin();
  rtc.begin();
  lcd.backlight();
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(21, 17, 00);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(5, 8, 2023);   // Set the date to January 1st, 2014
}

void loop()
{
  // Get data from the DS3231
  t = rtc.getTime();
  lcd.setCursor(0,0);
  // Send date over lcd connection
  lcd.print(t.date, DEC);
  lcd.print(" ");
  mon=rtc.getMonthStr();
  lcd.print(mon.substring(0,3));
  lcd.print(" ");
  lcd.print(t.year, DEC);
  lcd.setCursor(12, 0);
  day=rtc.getDOWStr();
  lcd.print(day.substring(0,3));
  
  // Send Day-of-Week and time
  lcd.setCursor(0,1);
  lcd.print(t.hour, DEC);
  lcd.print(":");
  lcd.print(t.min, DEC);
  lcd.print(":");
  lcd.print(t.sec, DEC);
  delay (1000);
}
