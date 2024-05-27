#ifndef L298N_MOTION_HPP
#define L298N_MOTION_HPP

#include "def.hpp"
#include "component.hpp"
#include "L298N.hpp"
#include "motion.hpp"

#define WEIGHT 0.5f

template <
    UInt8 LeftSpeedPin,     // ENA
    UInt8 LeftForwardPin,   // IN1
    UInt8 LeftBackwardPin,  // IN2
    UInt8 RightSpeedPin,    // ENA
    UInt8 RightForwardPin,  // IN1
    UInt8 RightBackwardPin> // IN2
class L298NMotion : public Motion
{
public:
private:
    L298N<LeftSpeedPin, LeftForwardPin, LeftBackwardPin> left_wheel;
    L298N<RightSpeedPin, RightForwardPin, RightBackwardPin> right_wheel;
    Int8 target_velocity;
    Int8 target_angular_velocity;
    Int8 velocity;
    Int8 angular_velocity;

public:
    inline L298NMotion() : left_wheel(), right_wheel(), velocity(0), angular_velocity(0) {}

    auto setup() -> void override
    {
        left_wheel.setup();
        right_wheel.setup();
    }

    auto process(UInt p_delta) -> void override
    {
        // Smooth out.
        velocity += (target_velocity - velocity) * WEIGHT;
        angular_velocity += (target_angular_velocity - angular_velocity) * WEIGHT;

        // Intergrate velocity and angular_velocity together.
        const Int16 raw_left_wheel_speed = (velocity + angular_velocity) * 2;
        const Int16 raw_right_wheel_speed = (velocity - angular_velocity) * 2;

        const Bool reverse_left_wheel = raw_left_wheel_speed < 0;
        const UInt8 left_wheel_speed = constrain(abs(raw_left_wheel_speed), 0, UINT8_MAX);

        const Bool reverse_right_wheel = raw_right_wheel_speed < 0;
        const UInt8 right_wheel_speed = constrain(abs(raw_right_wheel_speed), 0, UINT8_MAX);

        left_wheel.drive(left_wheel_speed, reverse_left_wheel);
        right_wheel.drive(right_wheel_speed, reverse_right_wheel);

        // Process components.
        left_wheel.process(p_delta);
        right_wheel.process(p_delta);
    }

    auto get_velocity() const -> Int8 override
    {
        return velocity;
    }

    auto set_velocity(Int8 p_velocity) -> void override
    {
        target_velocity = p_velocity;
    }

    auto get_angular_velocity() const -> Int8 override
    {
        return angular_velocity;
    }

    auto set_angular_velocity(Int8 p_angular_velocity) -> void override
    {
        target_angular_velocity = p_angular_velocity;
    }
};

#endif // L298N_MOTION_HPP