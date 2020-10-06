void cycle_rainbow_desaturated()
{
  int rate = 20;
  int start_hue;
  int delta_hue = 5;

  start_hue = -1 * millis() / rate;
  for (int i = 0; i < NUM_LEDS; i++)

  {
    leds[i] = CHSV(start_hue, beatsin16(10, 50, 255), 255);
    start_hue += delta_hue;
  };
}
