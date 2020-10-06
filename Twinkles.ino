void twinkles()
{
  EVERY_N_MILLIS(30)
  {
    // Make each pixel brighter or darker, depending on
    // its 'direction' flag.
    brightenOrDarkenEachPixel(FADE_IN_SPEED, FADE_OUT_SPEED);

    // Now consider adding a new random twinkle
    if (random8() < DENSITY)
    {
      int pos = random16(NUM_LEDS);
      if (!leds[pos])
      {
        leds[pos] = ColorFromPalette(currentPalette, random8(), STARTING_BRIGHTNESS, LINEARBLEND);
        setPixelDirection(pos, GETTING_BRIGHTER);
      }
    }
  }
}

void cloudTwinkles()
{
  targetPalette = CloudColors_p; // Blues and whites!
  colortwinkles();
}

void rainbowTwinkles()
{
  targetPalette = RainbowColors_p;
  colortwinkles();
}

void snowTwinkles()
{
  CRGB w(85, 85, 85), W(CRGB::White);

  targetPalette = CRGBPalette16(W, W, W, W, w, w, w, w, w, w, w, w, w, w, w, w);
  colortwinkles();
}

void incandescentTwinkles()
{
  CRGB l(0xE1A024);

  targetPalette = CRGBPalette16(l, l, l, l, l, l, l, l, l, l, l, l, l, l, l, l);
  colortwinkles();
}