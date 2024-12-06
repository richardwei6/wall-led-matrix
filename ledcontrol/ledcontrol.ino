#include <FastLED.h>

#define LED_PIN 18       // GPIO pin connected to DIN of the first WS2812B LED
#define NUM_LEDS 36      // Total number of LEDs
#define COLOR_ORDER GRB  // Color order for WS2812B
#define LED_TYPE WS2812B // Specify the LED type
#define GRID_WIDTH 6     // Number of columns
#define GRID_HEIGHT 6    // Number of rows

CRGB leds[NUM_LEDS];     // Array to hold LED data

void setup() {
  // Initialize FastLED
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(128); // Adjust brightness (0-255)
}

void loop() {
  // Example: Light up the grid row by row
  for (int row = 0; row < GRID_HEIGHT; row++) {
    for (int col = 0; col < GRID_WIDTH; col++) {
      int ledIndex = row * GRID_WIDTH + col; // Calculate LED index
      leds[ledIndex] = CRGB::Blue;          // Set the LED to blue
    }
    FastLED.show();
    delay(500);                             // Wait 500ms
  }

  // Turn off all LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(500);                               // Wait 500ms
}
