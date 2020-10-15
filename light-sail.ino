#include <Adafruit_NeoPixel.h>

#define NEO_PIXEL_PIN 12
#define NEO_PIXEL_LENGTH 100

Adafruit_NeoPixel pixels(NEO_PIXEL_LENGTH, NEO_PIXEL_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
    Serial.begin(115200);
    pixels.begin();
    pixels.show();
}

uint16_t hue;

void loop() {
    uint32_t rgb = pixels.gamma32(pixels.ColorHSV(hue, 255, 168));
    hue += 100;

    Serial.print("Red = "); Serial.print(rgb >> 16 & 0xff, HEX);
    Serial.print(", Green = "); Serial.print(rgb >> 8 & 0xff, HEX);
    Serial.print(", Blue = "); Serial.println(rgb >> 0 & 0xff, HEX);

    pixels.fill(rgb);
    pixels.show();

    delay(50);
}
