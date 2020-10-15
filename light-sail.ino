#include <Adafruit_NeoPixel.h>

#define NEO_PIXEL_PIN 12
#define NEO_PIXEL_LENGTH 100
#define COLOR_LEVEL_MAX 151
#define COLOR_LEVEL_STEP 10

Adafruit_NeoPixel pixels(NEO_PIXEL_LENGTH, NEO_PIXEL_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
    Serial.begin(115200);
    pixels.begin();
}

int red = 0;
int green = 0xff;
int blue = 0;

void loop() {
    int old_red = red;
    red = green;
    green = blue;
    blue = old_red;

    Serial.print("Red = "); Serial.print(red, HEX);
    Serial.print(", Green = "); Serial.print(green, HEX);
    Serial.print(", Blue = "); Serial.println(blue, HEX);

    pixels.clear();
    for (int c = 0; c < COLOR_LEVEL_MAX; c += COLOR_LEVEL_STEP ) {
        for (int i = 0; i < NEO_PIXEL_LENGTH; i++) {
            pixels.setPixelColor(i, pixels.Color(c & red, c & green, c & blue));
        }
        pixels.show();
        delay(100);
    }

    delay(500);
}
