#include <FastLED.h>

// Example showing how to use FastLED color functions
// even when you're NOT using a "pixel-addressible" smart LED strip.
//
// This example is designed to control an "analog" RGB LED strip
// (or a single RGB LED) being driven by Arduino PWM output pins.
// So this code never calls FastLED.addLEDs() or FastLED.show().
//
// This example illustrates one way you can use just the portions 
// of FastLED that you need.  In this case, this code uses just the
// fast HSV color conversion code.
// 
// In this example, the RGB values are output on three separate
// 'analog' PWM pins, one for red, one for green, and one for blue.
 
#define REDPIN_1   3
#define GREENPIN_1 5
#define BLUEPIN_1  6

#define REDPIN_2   9
#define GREENPIN_2 10
#define BLUEPIN_2  11 

//#define REDPIN_3   9
//#define GREENPIN_3 10
//#define BLUEPIN_3  11 

// Mega pins:
//#define REDPIN_1   2
//#define GREENPIN_1 3
//#define BLUEPIN_1  4
//
//#define REDPIN_2   5
//#define GREENPIN_2 6
//#define BLUEPIN_2  7 
//
//#define REDPIN_3   8
//#define GREENPIN_3 9
//#define BLUEPIN_3  10 

void setup() {
  pinMode(REDPIN_1,   OUTPUT);
  pinMode(GREENPIN_1, OUTPUT);
  pinMode(BLUEPIN_1,  OUTPUT);
  
  pinMode(REDPIN_2,   OUTPUT);
  pinMode(GREENPIN_2, OUTPUT);
  pinMode(BLUEPIN_2,  OUTPUT);
  
  pinMode(REDPIN_3,   OUTPUT);
  pinMode(GREENPIN_3, OUTPUT);
  pinMode(BLUEPIN_3,  OUTPUT);

  // Flash the "hello" color sequence: R, G, B, black.
  colorBars();
}

// showAnalogRGB: this is like FastLED.show(), but outputs on 
// analog PWM output pins instead of sending data to an intelligent,
// pixel-addressable LED strip.
// 
// This function takes the incoming RGB values and outputs the values
// on three analog PWM output pins to the r, g, and b values respectively.
void showAnalogRGB_1( const CRGB& rgb)
{
  analogWrite(REDPIN_1,   rgb.r );
  analogWrite(GREENPIN_1, rgb.g );
  analogWrite(BLUEPIN_1,  rgb.b );
}

void showAnalogRGB_2( const CRGB& rgb)
{
  analogWrite(REDPIN_2,   rgb.r );
  analogWrite(GREENPIN_2, rgb.g );
  analogWrite(BLUEPIN_2,  rgb.b );
}

void showAnalogRGB_3( const CRGB& rgb)
{
  analogWrite(REDPIN_3,   rgb.r );
  analogWrite(GREENPIN_3, rgb.g );
  analogWrite(BLUEPIN_3,  rgb.b );
}


// colorBars: flashes Red, then Green, then Blue, then Black.
// Helpful for diagnosing if you've mis-wired which is which.
void colorBars()
{
  showAnalogRGB_1( CRGB::Red );   delay(300);
  showAnalogRGB_1( CRGB::Green ); delay(300);
  showAnalogRGB_1( CRGB::Blue );  delay(300);
  showAnalogRGB_1( CRGB::Black ); delay(300);
  
  showAnalogRGB_2( CRGB::Red );   delay(300);
  showAnalogRGB_2( CRGB::Green ); delay(300);
  showAnalogRGB_2( CRGB::Blue );  delay(300);
  showAnalogRGB_2( CRGB::Black ); delay(300);
  
  showAnalogRGB_3( CRGB::Red );   delay(300);
  showAnalogRGB_3( CRGB::Green ); delay(300);
  showAnalogRGB_3( CRGB::Blue );  delay(300);
  showAnalogRGB_3( CRGB::Black ); delay(300);
}

//Cycle through a white flash on each group
void strobeWhite()
{
  showAnalogRGB_3( CRGB::Black );   delay(30);
  showAnalogRGB_1( CRGB::White );   delay(30);
  
  showAnalogRGB_1( CRGB::Black );   delay(30);
  showAnalogRGB_2( CRGB::White );   delay(30);
  
  showAnalogRGB_2( CRGB::Black );   delay(30);
  showAnalogRGB_3( CRGB::White );   delay(30);
}



//Cycle through all the colours with a shift on each group
void rainbow()
{
  static uint8_t hue;
  hue = hue + 1;
  
  showAnalogRGB_1( CHSV( hue, 255, 255) );
  showAnalogRGB_2( CHSV( hue+50, 255, 255) );
  showAnalogRGB_3( CHSV( hue+100, 255, 255) );
  
  delay(10);
}


void loop() 
{
  rainbow();
}

