
void pulse_white()
{
  int start_index = 100;
  // start_index = -1 * millis() / 50;
  start_index = -150 + -1 * millis() / 175;
  // fill_solid(leds, NUM_LEDS, CHSV(start_index, 255, beatsin16(30, 50, 255))); // Set all to Off.
  // fill_solid(leds, NUM_LEDS, CHSV(start_index, 255, beatsin16(30, 50, 255))); // Set all to Off.
  // CRGB color = ColorFromPalette(currentPalette, start_index, beatsin16(20, 50, 255), LINEARBLEND);
  fill_solid(leds, NUM_LEDS, CHSV(255, 0, beatsin16(15, 50, 255)));
  start_index += 1;
}