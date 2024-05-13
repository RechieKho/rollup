#ifndef L298N_HPP
#define L298N_HPP

#include "def.hpp"
#include "component.hpp"

template <
    UInt8 SpeedPin,    // ENA
    UInt8 ForwardPin,  // IN1
    UInt8 BackwardPin> // IN2
class L298N : public Component
{
public:
private:
    UInt8 speed;
    Bool reverse;

public:
    inline L298N() : speed(0), reverse(false) {}
    ~L298N() {}

    auto setup() -> void override
    {
        pinMode(SpeedPin, OUTPUT);
        pinMode(ForwardPin, OUTPUT);
        pinMode(BackwardPin, OUTPUT);
    }

    auto process(UInt p_delta) -> void override
    {
        analogWrite(SpeedPin, speed);
        if (reverse)
        {
            digitalWrite(ForwardPin, LOW);
            digitalWrite(BackwardPin, HIGH);
        }
        else
        {
            digitalWrite(ForwardPin, HIGH);
            digitalWrite(BackwardPin, LOW);
        }
    }

    auto drive(UInt8 p_speed, Bool p_reverse = false) -> void
    {
        speed = p_speed;
        reverse = p_reverse;
    }
};

#endif // L298N_HPP