#include <Adafruit_NeoPixel.h>

#define PIN 2 // input pin Neopixel is attached to

#define NUMPIXELS 12 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int pointer = 0;
int buttonState = 0;

void setup()
{
  pinMode(11, INPUT);

  // Initialize the NeoPixel library.
  pixels.begin();
}

void loop()
{
  setColor();
  buttonState = digitalRead(11);

  if (buttonState == HIGH)
  {
    if (pointer == NUMPIXELS)
      pointer = 0;
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(pointer, pixels.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    delay(delayval);
    pointer++;
  }
}

// setColor()
// picks random values to set for RGB
void setColor()
{
  redColor = random(0, 255);
  greenColor = random(0, 255);
  blueColor = random(0, 255);
}