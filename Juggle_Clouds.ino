void juggle_clouds()
{
  fadeToBlackBy(leds, NUM_LEDS, 20);
  int start_index;
  int delta_hue = 25;
  start_index = -1 * millis() / 10;
  for (int i = 0; i < 6; i++)
  {
    leds[beatsin16(i + 6, 0, NUM_LEDS - 1)] |= ColorFromPalette(CloudColors_p, start_index, 255, LINEARBLEND);
    ;
    start_index += delta_hue;
  }
}