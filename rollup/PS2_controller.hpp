#ifndef PS2_CONTROLLER_HPP
#define PS2_CONTROLLER_HPP

#include <Arduino.h>
#include <DigitalIO.h>
#include <PsxControllerHwSpi.h>

#include "controller.hpp"

template <UInt8 AttentionPin>
class PS2Controller : public Controller
{
public:
private:
    /* Quick fix because of this issue: https://github.com/SukkoPera/controllerNewLib/issues/31 */
    mutable PsxControllerHwSpi<AttentionPin> controller;

    Bool prepared;

public:
    inline PS2Controller() : controller(), prepared(false) {}

    auto process(UInt p_delta) -> void override
    {
        if (!prepared || !controller.read())
        {
            prepared = false;
            if (!controller.begin())
                return;
            prepared = true;
            delay(300);
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

    // Remove stick support.
    // auto get_left_stick_axes() const -> Tuple<Float, Float> override
    //{
    //     UInt8 x;
    //     UInt8 y;
    //
    //     if (!controller.getLeftAnalog(x, y))
    //         return Tuple<Float, Float>(0, 0);
    //
    //     const Float normalized_x = (Float)(x - UINT8_MAX / 2) / INT8_MAX;
    //     const Float normalized_y = (Float)(y - UINT8_MAX / 2) / INT8_MAX;
    //
    //     return Tuple<Float, Float>(normalized_x, normalized_y);
    // }

    // Remove stick support.
    // auto get_right_stick_axes() const -> Tuple<Float, Float> override
    //{
    //     UInt8 x;
    //     UInt8 y;
    //
    //     if (!controller.getRightAnalog(x, y))
    //         return Tuple<Float, Float>(0, 0);
    //
    //     const Float normalized_x = (Float)(x - UINT8_MAX / 2) / INT8_MAX;
    //     const Float normalized_y = (Float)(y - UINT8_MAX / 2) / INT8_MAX;
    //
    //     return Tuple<Float, Float>(normalized_x, normalized_y);
    // }
};

#endif // PS2_CONTROLLER_HPP