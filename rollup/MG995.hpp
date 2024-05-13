#ifndef MG995_HPP
#define MG995_HPP

#include "def.hpp"
#include "component.hpp"

template <
    UInt8 RotationPin>
class MG995 : public Component
{
public:
private:
    UInt8 rotation_duty_cycle; // 0 => 0 degree, 255 => 360 degree.

public:
    inline MG995() : rotation_duty_cycle(0) {}
    ~MG995() {}

    auto setup() -> void override
    {
        pinMode(RotationPin, OUTPUT);
    }

    auto process(UInt p_delta) -> void override
    {
        analogWrite(RotationPin, rotation_duty_cycle);
    }

    auto set_rotation_degree(Float p_degree) -> void
    {
        Float normalized = p_degree;
        while (normalized < 0)
            normalized += 360;
        while (normalized > 360)
            normalized -= 360;
        rotation_duty_cycle = (p_degree / 360) * UINT8_MAX;
    }

    auto set_rotation_duty_cycle(UInt8 p_duty_cycle) -> void
    {
        rotation_duty_cycle = p_duty_cycle;
    }
};

#endif // MG995_HPP