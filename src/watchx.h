#ifndef __watchx__
#define __watchx__

//OLED
#define OLED_CS A5 
#define OLED_DC A3 
#define OLED_RESET A4

//LED
#define LEDL 13
#define LEDR 6

//BUTTON
#define BUTTON1 8
#define BUTTON2 11
#define BUTTON3 10

//BUZZER
#define BUZZER 9

//BLUETOOTH
#define BLUEFRUIT_SPI_CS A2
#define BLUEFRUIT_SPI_IRQ 0
#define BLUEFRUIT_SPI_RST A1

//BMP

//CHARGE
#define CHARGESTATUS 5

//BATTERY
#define _VDR1 10000.0
#define _VDR2 10000.0
#define BATTERY_POWER 4
#define BATTERY_READ A11
extern const float _VDIVIDER;

// PROTOTYPES
inline void setup_buttons();
inline void setup_leds();
void setup_watchx();

int get_batteryPercentance();
float get_batteryVoltage();
unsigned int get_batteryRaw();

bool get_usbStatus();
bool get_chargeStatus(); 

// DATAs
extern const unsigned char PROGMEM logoWatchX [];
#endif
