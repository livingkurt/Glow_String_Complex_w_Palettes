void shooting_star()
{
  Serial.println("pattern_3");
  for (int i = 0; i < NUM_LEDS; i++)
  {

    //    int pos = beatsin16(10,0,NUM_LEDS);
    int start_index;
    int delta_hue = 5;
    start_index = -1 * millis() / 10;
    leds[i] += CHSV(start_index, 255, 255);
    // leds[i] += ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
    // leds[NUM_LEDS - i] += CHSV(start_hue, 255, 255);
    //    leds[i + 72] += CHSV( 255, 0, 255);

    FastLED.show();
    delay(30);
    fadeToBlackBy(leds, NUM_LEDS, 30);
    FastLED.show();
    start_index += delta_hue;
  }
}