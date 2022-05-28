#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PackPIN 12

// https://learn.adafruit.com/adafruit-neopixel-uberguide/neomatrix-library
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, PackPIN,
                                               NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                                   NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                                               NEO_GRB + NEO_KHZ800);

void setup()
{
  // put your setup code here, to run once:
  matrix.begin();
  matrix.setBrightness(20);
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 16; ++j)
    {
      if (rand() % 2 == 0)
      {
        matrix.drawPixel(i, j, matrix.Color(0, 0, 0));
      }
      else
      {
        matrix.drawPixel(i, j, matrix.Color(255, 255, 255));
      }
    }
  }

  matrix.show();
  delay(100);
}