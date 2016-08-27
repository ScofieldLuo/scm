#ifndef _ADAFRUIT_SSD1306_TEXT_H
#define _ADAFRUIT_SSD1306_TEXT_H

/*********************************************************************
This is a library for our Monochrome OLEDs based on SSD1306 drivers
  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98
These displays use SPI to communicate, 4 or 5 pins are required to  
interface
Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!
Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/


#include "Adafruit_SSD1306.h"


class Adafruit_SSD1306_text : public Adafruit_GFX {
 public:
  void _init();
  void _scm(String s);

 private:
    int _getlines(String s);
    String _getlinestr(String s, int line);

};

#endif // _ADAFRUIT_SSD1306_TEXT_H
