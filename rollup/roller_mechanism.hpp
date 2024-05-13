#ifndef ROLLER_MECHANISM_HPP
#define ROLLER_MECHANISM_HPP

#include "def.hpp"
#include "timer.hpp"
#include "mechanism.hpp"
#include "BTS7960.hpp"
#include "MG995.hpp"
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
    MG995<ShovelRotationPin> shovel;
    Relay<LiftRelayPin> lift;
    BTS7960<RollerForwardSpeedPin, RollerBackwardSpeedPin> roller;

public:
    inline RollerMechanism() : dispatch_timer(), shovel(), lift(), roller() {}

    auto setup() -> void override
    {
        dispatch_timer.setup();
        shovel.setup();
        lift.setup();
        roller.setup();
    }

    auto process(UInt p_delta) -> void override
    {
        dispatch_timer.process(p_delta);

        if (!dispatch_timer.is_completed())
            roller.drive(ROLLER_SPEED);
        else
            roller.drive(0);

        shovel.process(p_delta);
        lift.process(p_delta);
        roller.process(p_delta);
    }

    auto prepare_capture() -> void override
    {
        lift.off();
        shovel.set_rotation_degree(0);
    }

    auto capture() -> void override
    {
        shovel.set_rotation_degree(90);
    }

    auto prepare_dispatch() -> void override
    {
        lift.on();
    }

    auto dispatch() -> void override
    {
        if (dispatch_timer.is_completed())
            dispatch_timer.start(DISPATCH_DURATION);
    }
};

#endif // ROLLER_MECHANISM_HPP