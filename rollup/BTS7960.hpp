#ifndef BTS7960_HPP
#define BTS7960_HPP

// I don't know `BTS` is related to south korea or not.

#include "def.hpp"
#include "component.hpp"

template <
    UInt8 ForwardSpeedPin,
    UInt8 BackwardSpeedPin>
class BTS7960 : public Component
{
public:
private:
    UInt8 speed;
    Bool reverse;

public:
    inline BTS7960() : speed(0), reverse(false) {}
    ~BTS7960() {}

    auto setup() -> void override
    {
        pinMode(ForwardSpeedPin, OUTPUT);
        pinMode(BackwardSpeedPin, OUTPUT);
    }

    auto process(UInt p_delta) -> void override
    {
        if (reverse)
        {
            analogWrite(ForwardSpeedPin, 0);
            analogWrite(BackwardSpeedPin, speed);
        }
        else
        {
            analogWrite(ForwardSpeedPin, speed);
            analogWrite(BackwardSpeedPin, 0);
        }
    }

    auto drive(UInt8 p_speed, Bool p_reverse = false) -> void
    {
        speed = p_speed;
        reverse = p_reverse;
    }
};

#endif // BTS7960_HPP