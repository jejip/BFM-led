# BFM LED
An Arduino programme to drive three groups of analog led strips.   Different patterns and animations can be shown.

## Installing
The FastLED library is used because of its easy way to convert HSV (Hue, Saturation, Value (Luminance)) to RGB values, which the Arduino outputs on its PWM channels.
So before running, install the library in your Arduino/libraries folder.

## Usage
It’s built for an Arduino Mega, because that one’s got PWM channels for three groups of led strips. A cheaper board would be the Teensy.

