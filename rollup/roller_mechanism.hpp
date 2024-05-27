#ifndef ROLLER_MECHANISM_HPP
#define ROLLER_MECHANISM_HPP

#include <Servo.h>

#include "def.hpp"
#include "timer.hpp"
#include "mechanism.hpp"
#include "BTS7960.hpp"
#include "relay.hpp"

#define DISPATCH_DURATION 1000
#define ROLLER_SPEED 255

template <
    UInt8 ShovelRotationPin,
    UInt8 LiftRelayPin,
    UInt8 RollerForwardSpeedPin,
    UInt8 RollerBackwardSpeedPin>
class RollerMechanism : public Mechanism
{
public:
private:
    Timer dispatch_timer;
    Relay<LiftRelayPin> lift;
    BTS7960<RollerForwardSpeedPin, RollerBackwardSpeedPin> roller;

    Servo shovel;
    UInt8 shovel_position;
    Bool is_roller_reversed;

public:
    inline RollerMechanism() : dispatch_timer(), shovel(), lift(), roller(), shovel_position(110), is_roller_reversed(false) {}

    auto setup() -> void override
    {
        shovel.attach(ShovelRotationPin);
        shovel.write(shovel_position);
        dispatch_timer.setup();
        lift.setup();
        roller.setup();
    }

    auto process(UInt p_delta) -> void override
    {
        dispatch_timer.process(p_delta);

        if (!dispatch_timer.is_completed())
            roller.drive(ROLLER_SPEED, is_roller_reversed);
        else
            roller.drive(0);

        shovel.write(shovel_position);
        lift.process(p_delta);
        roller.process(p_delta);
    }

    auto prepare_capture() -> void override
    {
        lift.off();
        shovel_position = 110;
    }

    auto capture() -> void override
    {
        shovel_position = 1;
    }

    auto prepare_dispatch() -> void override
    {
        lift.on();
    }

    auto dispatch() -> void override
    {
        if (dispatch_timer.is_completed())
        {
            is_roller_reversed = false;
            dispatch_timer.start(DISPATCH_DURATION);
        }
    }

    auto revert_dispatch() -> void override
    {
        if (dispatch_timer.is_completed())
        {
            is_roller_reversed = true;
            dispatch_timer.start(DISPATCH_DURATION);
        }
    }
};

#endif // ROLLER_MECHANISM_HPP