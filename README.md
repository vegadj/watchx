# WatchX 

Programable smart watch powered by arduino. [Official Site](http://www.watchx.io)

## Usage

Detailed usage will be described in future. For now read the header file, all names are self described.

#### Functions
 * `inline void setup_buttons()` sets pinmodes for buttons
 * `inline void setup_leds()` sets pinmodes for leds
 * `void setup_watchx()` sets buttons and leds, and initiate i2c
 * `unsigned int get_batteryRaw()` get battery voltage raw value from digital read. from 0 to 1024
 * `float get_batteryVoltage()` get battery voltage. calculated by voltage divider.
 * `get_batteryPercentance()` get battery capacity as percent with %5 precision. actual percent may vary on your battery condition and 3rd party batteries. This function is optimized for original watchX battery in good condition.
 * `bool get_usbStatus()` returns the status of usb
 * `bool get_chargeStatus()` returns the charging status
 

#### Defined pin names and variables

| Part | Defined Names | 
| ---- | ----- |
| Oled |  OLED_CS, OLED_DC, OLED_RESET |
| Led | LEDL, LEDR |
| Buttons | BUTTON1 BUTTON2 BUTTON3 |
| Buzzer | BUZZER |
| Bluetooth | BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST |
| Charge | CHARGESTATUS |
| Bmp | *to do* |
| Battery | BATTERY_POWER, BATTERY_READ |


`const unsigned char logoWatchX [] PROGMEM` this is watchX logo as bitmap image. You can use it on your favorite oled library bitmap drawer. The array size is 128x29px and uses 464bytes of memory.


## FAQ

### What is this library for ?

Every watchX project has repeated first lines such as pin assignments or basic battery functions. This library defines all available pins and gives you the low level fuction you need for project. 

### What is this library NOT for ? 

This library aims the only basic level stuffs and does not deal with higher levels suchs as using OLED screen. The reason for this is since there are hardware limitations in every arduino proccessor and there is no perfect library for every hardware (OLED, bluetooth, BPM etc). So if there is something that limits some use case of minority of watchX user or not for every use case, basicly it will not include in the library for now.  

### Why should I use ?
* Save time while programing basic functions and defining pins in your projects
* Global names for pins and functions in your project for you and community, makes your project readable 
* Make your projects for future proof

### There is something wrong or missing functionality ? 
If you are thinking that; 
* feel free to connect;
* fix it and send pull request
* discuss at offical [watchx forum](https://community.watchx.io)
