
//#include <avr/pgmspace.h>
#include <Adafruit_GFX.h>
#include <ST7558.h>
#include <Wire.h>
#define RST A0
#include <DMXSerial.h>




ST7558 lcd = ST7558(RST);

//extern const unsigned char flecha[];
//extern const unsigned char cara[];
//extern const unsigned char logo16[];
//extern const unsigned char black[];

int8_t i=88;




void setup(){
  DMXSerial.init(DMXReceiver);
  pinMode(5, INPUT);
  lcd.init();
  lcd.setContrast(65);
 // lcd.setRotation(0);
  lcd.setTextSize(1);
  lcd.clearDisplay();
  lcd.setTextColor(BLACK);
  lcd.setCursor(15,0);
  lcd.print("Hello World!");
  lcd.display();
  delay(2000);
}

void loop()
{
    // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  
 // if (lastPacket < 5000) {
    // read recent DMX values and set pwm levels 
  lcd.clearDisplay();
  lcd.setCursor(0,0);
  lcd.print("ch1");
  lcd.setCursor(24,0);
  lcd.print(DMXSerial.read(1));
  
  lcd.setCursor(0,9);
  lcd.print("ch2");
  lcd.setCursor(24,9);
  lcd.print(DMXSerial.read(2));
  
  lcd.setCursor(0,18);
  lcd.print("ch3");
  lcd.setCursor(24,18);
  lcd.print(DMXSerial.read(3));

  lcd.setCursor(0,27);
  lcd.print("ch4");
  lcd.setCursor(24,27);
  lcd.print(DMXSerial.read(4));

  lcd.setCursor(0,36);
  lcd.print("ch5");
  lcd.setCursor(24,36);
  lcd.print(DMXSerial.read(5));
  
  lcd.setCursor(0,45);
  lcd.print("ch6");
  lcd.setCursor(24,45);
  lcd.print(DMXSerial.read(6));
  
  lcd.setCursor(45,0);
  lcd.print("ch7");
  lcd.setCursor(76,0);
  lcd.print(DMXSerial.read(7));
  
  lcd.setCursor(45,9);
  lcd.print("ch8");
  lcd.setCursor(76,9);
  lcd.print(DMXSerial.read(8));

  lcd.setCursor(45,18);
  lcd.print("ch9");
  lcd.setCursor(76,18);
  lcd.print(DMXSerial.read(9));

  lcd.setCursor(45,27);
  lcd.print("ch10");
  lcd.setCursor(76,27);
  lcd.print(DMXSerial.read(10));

  lcd.setCursor(45,36);
  lcd.print("ch11");
  lcd.setCursor(76,36);
  lcd.print(DMXSerial.read(11));

  lcd.setCursor(45,45);
  lcd.print("ch12");
  lcd.setCursor(76,45);
  lcd.print(DMXSerial.read(12));
  
  
  lcd.display();
  delay(1000);
  lcd.clearDisplay();

    
  //} else {

  lcd.clearDisplay();
  lcd.setTextColor(BLACK);
  lcd.setCursor(15,0);
  lcd.print("SIN DMX!");
  lcd.display();
  delay(2000);
    
  //} 
  
   
}






