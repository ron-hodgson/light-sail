#include <Adafruit_NeoPixel.h>

#define NEO_PIXEL_PIN 12
#define NEO_PIXEL_LENGTH 100

Adafruit_NeoPixel pixels(NEO_PIXEL_LENGTH, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin();
}

void loop() {
    pixels.clear();

    for (int i = 0; i < NEO_PIXEL_LENGTH; i++) {
        pixels.setPixelColor(i, pixels.Color(150, 0, 0));
    }

    pixels.show();
    pixels.clear();

    for (int i = 0; i < NEO_PIXEL_LENGTH; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    }

    pixels.show();
    pixels.clear();

    for (int i = 0; i < NEO_PIXEL_LENGTH; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 150));
    }

    pixels.show();
}
