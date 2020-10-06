void split()
{
  int rate = 10;
  int split_value = 2;
  int row = NUM_LEDS / split_value;
  int start_index;
  int delta_hue = 5;

  start_index = -1 * millis() / rate;
  for (int i = 0; i < row; i++)
  {
    // leds[i] = CHSV(start_index, 255, 255);
    leds[i] = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
    leds[NUM_LEDS - 1 - i] = ColorFromPalette(currentPalette, start_index, 255, LINEARBLEND);
    // leds[NUM_LEDS - 1 - i] = CHSV(start_index, 255, 255);
    start_index += delta_hue;
  };
}
