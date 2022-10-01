#include <HIDKeyboard.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO 128
#define ALTO 64
#define OLED_RESET 4
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET); // Create a Adafruit Graphical class
  
uint8_t buf[8] = { 0 }; /* Keyboard report buffer */

  
#define KEY_LEFT_GUI 0x08
#define KEY_R 21
/*
#define KEY_ENTER 40

#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT    0x81
#define KEY_LEFT_ALT    0x82
#define KEY_LEFT_GUI    0x83
#define KEY_RIGHT_CTRL    0x84
#define KEY_RIGHT_SHIFT   0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_RIGHT_GUI   0x87
*/


HIDKeyboard keyboard; // Initialize HIDKeyboard object

void setup() {

  pinMode(2, INPUT);
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    //intro
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setCursor(5,5);
  oled.setTextSize(2);
  oled.print("USBcrack");
  oled.setCursor(0,25);
  oled.setTextSize(1);
  oled.print("[version 0.1]");
  oled.setCursor(0,35);
  oled.setTextSize(1);
  oled.print("[by Danyw24]");
  oled.display();
  Serial.begin(9600);
  delay(1500);
}

void loop() {
  if(digitalRead(2) == LOW){
    oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setCursor(5,5);
  oled.setTextSize(1);
  oled.print("[!]Crackeando...");
  oled.display();
  delay(2000);
    buf[0] = KEY_LEFT_GUI;
    buf[2] = KEY_R;

     Serial.write(buf, 8); // Send GUI+R keypress
     buf[0] = 0;
     buf[2] = 0;
    Serial.write(buf, 8); // Release key
    delay(100);
    keyboard.println("cmd");
    delay(1000);
    keyboard.println("echo Pwned");    
    oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setCursor(5,5);
  oled.setTextSize(1);
  oled.print("[+]Payload ejecutado");
  oled.display();
  delay(1500);
      
    
  
      
    }

  while(1);


}
