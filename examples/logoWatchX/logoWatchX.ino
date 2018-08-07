#include <watchx.h>
#include <Adafruit_SSD1306.h>

/* 
 * This example draws watchX logo into your oled display. 
 * Oled pins are predefined in your watchX library
 * To use you oled display you can use your favorite SSD1306 library 
 * In this example Adafruit_SSD1306 library is choosen for demonstration
 * Please make sure Adafruit_SSD1306 is installed onto your system 
*/

Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS); // setup oled pins 

void setup() {
  // put your setup code here, to run once:
  setup_watchx();
  display.begin(SSD1306_SWITCHCAPVCC); // init oled 
  display.clearDisplay(); // clear display buffer
  display.drawBitmap(0, 21, logoWatchX, 128, 29, 1); // buffer wathcX logo bitmap into oled
  display.display(); // show new buffer
}

void loop() {
  // put your main code here, to run repeatedly:

}
