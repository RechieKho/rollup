#include "main.hpp"
#include "L298N_motion.hpp"
#include "PS2_controller.hpp"
#include "roller_mechanism.hpp"

#define PS2_DAT 10
#define PS2_CMD 11
#define PS2_ATT 12
#define PS2_CLK 13

#define LEFT_WHEEL_ENA 3
#define LEFT_WHEEL_IN1 2
#define LEFT_WHEEL_IN2 4

#define RIGHT_WHEEL_ENA 3
#define RIGHT_WHEEL_IN1 2
#define RIGHT_WHEEL_IN2 4

#define SHOVEL_ROTATION_PIN 16
#define LIFT_RELAY_PIN 17
#define ROLLER_FORWARD_SPEED_PIN 6
#define ROLLER_BACKWARD_SPEED_PIN 9

Main app(
    new PS2Controller<PS2_ATT, PS2_CMD, PS2_DAT, PS2_CLK>(),
    new L298NMotion<
        LEFT_WHEEL_ENA, LEFT_WHEEL_IN1, LEFT_WHEEL_IN2,
        RIGHT_WHEEL_ENA, RIGHT_WHEEL_IN1, RIGHT_WHEEL_IN2>(),
    new RollerMechanism<
        SHOVEL_ROTATION_PIN,
        LIFT_RELAY_PIN,
        ROLLER_FORWARD_SPEED_PIN, ROLLER_BACKWARD_SPEED_PIN>());

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