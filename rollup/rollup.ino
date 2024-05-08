#include "main.hpp"
#include "L298N_motion.hpp"

#define LEFT_WHEEL_ENA 3
#define LEFT_WHEEL_IN1 2
#define LEFT_WHEEL_IN2 4

#define RIGHT_WHEEL_ENA 3
#define RIGHT_WHEEL_IN1 2
#define RIGHT_WHEEL_IN2 4

Main app(
    new Controller(),
    new L298NMotion(
        L298N(LEFT_WHEEL_ENA, LEFT_WHEEL_IN1, LEFT_WHEEL_IN2),
        L298N(RIGHT_WHEEL_ENA, RIGHT_WHEEL_IN1, RIGHT_WHEEL_IN2)),
    new Mechanism());

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