

void split_shooting_star()
{
  int rate = 10;
  int strobe = 50;
  int split_value = 4;
  int start_index;
  int delta_hue = 10;
  int row = NUM_LEDS / split_value;
  start_index = -1 * millis() / rate;

  for (int i = 0; i < row; i++)
  {
    // Row 1
    // leds[i] = CHSV(start_index, 0, 255);
    // leds[backwards(row, 2, i)] = CHSV(start_index, 255, 255);
    // leds[forwards(row, 2, i)] = CHSV(start_index, 255, 255);
    // leds[NUM_LEDS - 1 - i] = CHSV(start_index, 0, 255);
    leds[i] = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
    leds[backwards(row, 2, i)] = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
    leds[forwards(row, 2, i)] = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
    leds[NUM_LEDS - 1 - i] = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
    start_index += delta_hue;
    FastLED.show();
    hold(strobe);
    fadeToBlackBy(leds, NUM_LEDS, 20);
    FastLED.show();
  };
}