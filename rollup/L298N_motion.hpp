#ifndef L298N_MOTION_HPP
#define L298N_MOTION_HPP

#include "def.hpp"
#include "component.hpp"
#include "motion.hpp"

class L298N : public Component
{
public:
private:
    UInt8 speed_pin;    // ENA
    UInt8 forward_pin;  // IN1
    UInt8 backward_pin; // IN2

    UInt8 speed;
    Bool reverse;

public:
    L298N(UInt8 p_speed_pin, UInt8 p_forward_pin, UInt8 p_backward_pin);
    ~L298N() override;

    void setup() override;
    void process(UInt p_delta) override;

    void drive(UInt8 p_speed, Bool p_reverse = false);
};

class L298NMotion : public Motion
{
public:
private:
    L298N left_wheel;
    L298N right_wheel;
    Int8 velocity;
    Int8 angular_velocity;

public:
    L298NMotion(L298N p_left_wheel, L298N p_right_wheel);

    void setup() override;
    void process(UInt p_delta) override;
    Int8 get_velocity() const override;
    void set_velocity(Int8 p_velocity) override;
    Int8 get_angular_velocity() const override;
    void set_angular_velocity(Int8 p_degree) override;
};

#endif // L298N_MOTION_HPP