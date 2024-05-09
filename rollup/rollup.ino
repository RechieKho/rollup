#include "main.hpp"
#include "L298N_motion.hpp"
#include "PS2_controller.hpp"

#define LEFT_WHEEL_ENA 3
#define LEFT_WHEEL_IN1 2
#define LEFT_WHEEL_IN2 4

#define RIGHT_WHEEL_ENA 3
#define RIGHT_WHEEL_IN1 2
#define RIGHT_WHEEL_IN2 4

#define PS2_DAT 10
#define PS2_CMD 11
#define PS2_ATT 12
#define PS2_CLK 13

Main app(
    new PS2Controller<PS2_ATT, PS2_CMD, PS2_DAT, PS2_CLK>(),
    new L298NMotion<
        LEFT_WHEEL_ENA, LEFT_WHEEL_IN1, LEFT_WHEEL_IN2,
        RIGHT_WHEEL_ENA, RIGHT_WHEEL_IN1, RIGHT_WHEEL_IN2>(),
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