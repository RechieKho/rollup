#ifndef PS2_CONTROLLER_HPP
#define PS2_CONTROLLER_HPP

#include <Arduino.h>
#include <DigitalIO.h>
#include <PsxControllerBitBang.h>

#include "controller.hpp"

template <UInt8 AttentionPin, UInt8 CommandPin, UInt8 DataPin, UInt8 ClockPin>
class PS2Controller : public Controller
{
public:
private:
    PsxControllerBitBang<AttentionPin, CommandPin, DataPin, ClockPin> controller;

    Bool prepared;

public:
    inline PS2Controller() : controller(), prepared(false) {}

    auto process(UInt p_delta) -> void override
    {
        if (!controller.read() || !prepared)
        {
            prepared = false;

            if (!controller.begin())
                return;
            if (!controller.enterConfigMode())
                return;
            if (!controller.enableAnalogSticks())
                return;
            if (!controller.enableAnalogButtons())
                return;
            if (!controller.exitConfigMode())
                return;

            prepared = true;
        }
    }

    auto is_up_button_pressed() const -> Bool override
    {
        return controller.buttonPressed(PSB_PAD_UP);
    }

    auto is_down_button_pressed() const -> Bool override
    {
        return controller.buttonPressed(PSB_PAD_DOWN);
    }

    auto is_left_button_pressed() const -> Bool override
    {
        return controller.buttonPressed(PSB_PAD_LEFT);
    }

    auto is_right_button_pressed() const -> Bool override
    {
        return controller.buttonPressed(PSB_PAD_RIGHT);
    }

    auto is_triangle_button_pressed() const -> Bool override
    {
        return controller.buttonPressed(PSB_TRIANGLE);
    }

    auto is_circle_button_pressed() const -> Bool override
    {
        return controller.buttonPressed(PSB_CIRCLE);
    }

    auto is_cross_button_pressed() const -> Bool override
    {
        return controller.buttonPressed(PSB_CROSS);
    }

    auto is_square_button_pressed() const -> Bool override
    {
        return controller.buttonPressed(PSB_SQUARE);
    }

    auto get_left_stick_axes() const -> Tuple<Float, Float> override
    {
        UInt8 x;
        UInt8 y;

        if (!controller.getLeftAnalog(x, y))
            return Tuple<Float, Float>(0, 0);

        const Float normalized_x = (Float)(x - UINT8_MAX / 2) / INT8_MAX;
        const Float normalized_y = (Float)(y - UINT8_MAX / 2) / INT8_MAX;

        return Tuple<Float, Float>(normalized_x, normalized_y);
    }

    auto get_right_stick_axes() const -> Tuple<Float, Float> override
    {
        UInt8 x;
        UInt8 y;

        if (!controller.getRightAnalog(x, y))
            return Tuple<Float, Float>(0, 0);

        const Float normalized_x = (Float)(x - UINT8_MAX / 2) / INT8_MAX;
        const Float normalized_y = (Float)(y - UINT8_MAX / 2) / INT8_MAX;

        return Tuple<Float, Float>(normalized_x, normalized_y);
    }
};

#endif // PS2_CONTROLLER_HPP