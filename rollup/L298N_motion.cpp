#include "L298N_motion.hpp"

#include <Arduino.h>

L298N::L298N(UInt8 p_speed_pin, UInt8 p_forward_pin, UInt8 p_backward_pin) : speed_pin(p_speed_pin), forward_pin(p_forward_pin), backward_pin(p_backward_pin), speed(0), reverse(false) {}

L298N::~L298N() {}

void L298N::setup()
{
    pinMode(speed_pin, OUTPUT);
    pinMode(forward_pin, OUTPUT);
    pinMode(backward_pin, OUTPUT);
}

void L298N::process(UInt p_delta)
{
    analogWrite(speed_pin, speed);
    if (reverse)
    {
        digitalWrite(forward_pin, LOW);
        digitalWrite(backward_pin, HIGH);
    }
    else
    {
        digitalWrite(forward_pin, HIGH);
        digitalWrite(backward_pin, LOW);
    }
}

void L298N::drive(UInt8 p_speed, Bool p_reverse)
{
    speed = p_speed;
    reverse = p_reverse;
}

L298NMotion::L298NMotion(L298N p_left_wheel, L298N p_right_wheel) : left_wheel(p_left_wheel), right_wheel(p_right_wheel), velocity(0), angular_velocity(0) {}

void L298NMotion::setup()
{
    left_wheel.setup();
    right_wheel.setup();
}

void L298NMotion::process(UInt p_delta)
{
    /// Intergrate velocity and angular_velocity together.
    const Int8 raw_left_wheel_speed = (Int8)map(velocity + angular_velocity, INT8_MIN + INT8_MIN, INT8_MAX + INT8_MAX, INT8_MIN, INT8_MAX);
    const Int8 raw_right_wheel_speed = (Int8)map(velocity - angular_velocity, INT8_MIN + INT8_MIN, INT8_MAX + INT8_MAX, INT8_MIN, INT8_MAX);

    const Bool reverse_left_wheel = raw_left_wheel_speed < 0;
    const UInt8 left_wheel_speed = abs(raw_left_wheel_speed) * 2;

    const Bool reverse_right_wheel = raw_right_wheel_speed < 0;
    const UInt8 right_wheel_speed = abs(raw_right_wheel_speed) * 2;

    left_wheel.drive(left_wheel_speed, reverse_left_wheel);
    right_wheel.drive(right_wheel_speed, reverse_right_wheel);
}

Int8 L298NMotion::get_velocity() const { return velocity; }

void L298NMotion::set_velocity(Int8 p_velocity) { velocity = p_velocity; }

Int8 L298NMotion::get_angular_velocity() const { return angular_velocity; }

void L298NMotion::set_angular_velocity(Int8 p_angular_velocity) { angular_velocity = p_angular_velocity; }