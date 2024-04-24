#include "main.hpp"

Main app(new Controller(), new Motion());

void setup()
{
  app.setup();
}

void loop()
{
  static UInt32 previous_time = millis();
  const UInt delta = UInt(millis() - previous_time);
  previous_time = millis();

  app.process(delta);
}