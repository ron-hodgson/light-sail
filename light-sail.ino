#include <Adafruit_NeoPixel.h>
#include "frames.h"

#define NEO_PIXEL_PIN 12

Adafruit_NeoPixel pixels(FRAMES_PIXELS, NEO_PIXEL_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
    Serial.begin(115200);
    pixels.begin();
    pixels.show();
}

unsigned long frame;
unsigned long nextFrameShow;

void loop() {
    if (millis() < nextFrameShow) {
        return;
    }
    nextFrameShow = millis() + FRAMES_MILLIS;

    Serial.print("Sending frame #"); Serial.println(frame + 1);

    for (int i = 0; i < FRAMES_PIXELS; i++) {
        pixels.setPixelColor(i, frames[frame * FRAMES_PIXELS + i]);
    }
    pixels.show();

    frame = (frame + 1) % FRAMES_LENGTH;
}
