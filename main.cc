#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const uint8_t mov_sensor_pin = 2;
const uint8_t relay_pin = 3;
LiquidCrystal_I2C LCD(0x27,16,2);
uint32_t relay_counter = 0;
uint8_t move_reg_flag = 0;
uint8_t move_unreg_flag = 1;

void setup()
{
  pinMode(relay_pin, OUTPUT);
  pinMode(mov_sensor_pin, INPUT);
	LCD.init();                     
	LCD.backlight();
	LCD.print("ActivationsCount");
  LCD.setCursor(0, 1);
	LCD.print(relay_counter);
  delay(100);
}

void loop()
{
    if (digitalRead(mov_sensor_pin))
	  {
      if(move_reg_flag == 0)
      {
	      move_reg_flag++;
        move_unreg_flag = 0;
        relay_counter++;
        LCD.setCursor(0, 1);
        digitalWrite(relay_pin, HIGH);
        LCD.print(relay_counter);
      }
      delay(10);
	  }
    else 
    {
      if(move_unreg_flag == 0)
      {
         move_reg_flag = 0;
         move_unreg_flag++;
          digitalWrite(relay_pin, LOW);
       // }
      }
      delay(10);
    }
}