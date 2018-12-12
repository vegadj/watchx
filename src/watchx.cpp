#include <Arduino.h>
#include <Wire.h>
#include <avr/pgmspace.h>
#include "watchx.h"

const float _VDIVIDER = (float) (_VDR2 / (_VDR1 + _VDR2));
const unsigned int _batteryPercentance [] PROGMEM = {
    // voltage raw values from [5,100] percentance with 5% increasement
    530, 537, 545, 552, 558, 562, 566, 569, 572, 575,
    579, 582, 588, 592, 598, 603, 609, 616, 623, 630
};

inline void setup_buttons() {
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
}

inline void setup_leds() { // do we really need to set output ? 
  pinMode(LEDL, OUTPUT);
  pinMode(LEDR, OUTPUT);
}

void setup_watchx() {
  setup_buttons();
  setup_leds();
  Wire.begin();
}

unsigned int get_batteryRaw() {
  unsigned int vraw;
  digitalWrite(BATTERY_POWER, HIGH);
  delay (50);
  vraw = analogRead (BATTERY_READ);
  digitalWrite(BATTERY_POWER, LOW);
  return vraw;
}

float get_batteryVoltage() {
  float voltage;
  voltage = get_batteryRaw() / 1024.0 * 3.35 / _VDIVIDER;
  return voltage;
}

int get_batteryPercentance() {
  int i;
  int vraw = get_batteryRaw();
  for (i=0; i<20; i+=1) {
      //Serial.println(i);
      //Serial.println(vraw);
      //Serial.println(_batteryPercentance[i]);
      //Serial.println();
      if (vraw <= pgm_read_word_near(&_batteryPercentance[i])) break;
     
  }
    
  return i*5;
}

bool get_usbStatus() {
    return (UDADDR & _BV(ADDEN)); 
}

bool get_chargeStatus() {
    return digitalRead(CHARGESTATUS);
}

const unsigned char logoWatchX [] PROGMEM = {
  // 'watchXlogo, 128x29px, 464byte
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x07, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x07, 0xfc, 0x00, 0x00, 0xfe, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xff, 0x00, 0x0f, 0xfc, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x01, 0xff, 0x80, 0x3f, 0xf8, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0xff, 0xc0, 0x3f, 0xf0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x7f, 0xe0, 0x7f, 0xe0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x3f, 0xe0, 0xff, 0xc0, 
  0xf1, 0xe1, 0xc3, 0xff, 0xf8, 0xff, 0xe1, 0xff, 0xf8, 0x7f, 0xff, 0x00, 0x1f, 0xf1, 0xff, 0x80, 
  0xf1, 0xe1, 0xc3, 0xff, 0xf8, 0xff, 0xe1, 0xff, 0xf8, 0x7f, 0xff, 0x00, 0x0f, 0xf9, 0xff, 0x00, 
  0xf1, 0xe1, 0xc3, 0xff, 0xf8, 0xff, 0xe1, 0xff, 0xf8, 0x7f, 0xff, 0x00, 0x07, 0xff, 0xfe, 0x00, 
  0xf1, 0xe1, 0xc0, 0x00, 0x78, 0xff, 0xe1, 0xff, 0xf8, 0x7f, 0xff, 0x00, 0x03, 0xef, 0xfc, 0x00, 
  0xf1, 0xe1, 0xc0, 0x00, 0x78, 0xf0, 0x01, 0xe0, 0x00, 0x78, 0x0f, 0x00, 0x03, 0xef, 0xf8, 0x00, 
  0xf1, 0xe1, 0xc0, 0x00, 0x78, 0xf0, 0x01, 0xe0, 0x00, 0x78, 0x0f, 0x00, 0x01, 0xdf, 0xf0, 0x00, 
  0xf1, 0xe1, 0xc3, 0xff, 0xf8, 0xf0, 0x01, 0xe0, 0x00, 0x78, 0x0f, 0x00, 0x00, 0xbf, 0xe0, 0x00, 
  0xf1, 0xe1, 0xc3, 0xff, 0xf8, 0xf0, 0x01, 0xe0, 0x00, 0x78, 0x0f, 0x00, 0x00, 0x7f, 0xd0, 0x00, 
  0xf1, 0xe1, 0xc3, 0xff, 0xf8, 0xf0, 0x01, 0xe0, 0x00, 0x78, 0x0f, 0x00, 0x00, 0xff, 0xf0, 0x00, 
  0xf1, 0xe1, 0xc3, 0xc0, 0x78, 0xf0, 0x01, 0xe0, 0x00, 0x78, 0x0f, 0x00, 0x01, 0xff, 0xf0, 0x00, 
  0xf1, 0xe1, 0xc3, 0xc0, 0x78, 0xf0, 0x01, 0xe0, 0x00, 0x78, 0x0f, 0x00, 0x03, 0xff, 0x78, 0x00, 
  0xff, 0xff, 0xc3, 0xc0, 0x78, 0xff, 0xe1, 0xff, 0xf8, 0x78, 0x0f, 0x00, 0x07, 0xfe, 0xfc, 0x00, 
  0xff, 0xff, 0xc3, 0xff, 0xf8, 0xff, 0xe1, 0xff, 0xf8, 0x78, 0x0f, 0x00, 0x0f, 0xfe, 0xfe, 0x00, 
  0xff, 0xff, 0xc3, 0xff, 0xf8, 0xff, 0xe1, 0xff, 0xf8, 0x78, 0x0f, 0x00, 0x1f, 0xf9, 0xff, 0x00, 
  0xff, 0xff, 0xc3, 0xff, 0xf8, 0xff, 0xe1, 0xff, 0xf8, 0x78, 0x0f, 0x00, 0x3f, 0xf0, 0xff, 0x80, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xe0, 0xff, 0xc0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x7f, 0xe0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x3f, 0xf0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x1f, 0xf8, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x0f, 0xfc, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x01, 0xfc, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x1c
};

