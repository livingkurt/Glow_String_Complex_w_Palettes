

void rainbow_sparkle()
{
  int start_hue;
  int delta_hue = 20;
  start_hue = -1 * millis() / 10;
  fill_solid(leds, NUM_LEDS, CHSV(start_hue, 255, 100)); // Set all to red.
  FastLED.show();
  int rand = random(NUM_LEDS);
  leds[rand] = CHSV(255, 0, 255); // Change To Random LED and change color to White
  FastLED.show();
  start_hue += delta_hue;
}