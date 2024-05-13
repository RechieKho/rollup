#ifndef RELAY_HPP
#define RELAY_HPP

#include "def.hpp"
#include "component.hpp"

template <
    UInt8 SwitchPin>
class Relay : public Component
{
public:
private:
public:
    auto setup() -> void override
    {
        pinMode(SwitchPin, OUTPUT);
    }

    auto set_active(Bool is_active) -> void
    {
        digitalWrite(SwitchPin, is_active ? HIGH : LOW);
    }

    auto on() -> void
    {
        digitalWrite(SwitchPin, HIGH);
    }

    auto off() -> void
    {
        digitalWrite(SwitchPin, LOW);
    }
};

#endif // RELAY_HPP