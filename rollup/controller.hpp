#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "def.hpp"
#include "component.hpp"
#include "tuple.hpp"

/// Abstract class for controller.
/// Controller interface is based on Dualshock 4 controller (https://manuals.playstation.net/document/en/ps4/basic/pn_controller.html).
class Controller : public Component
{
public:
private:
public:
    /// Virtual class.
    virtual ~Controller() = 0;

    /// Directional buttons.
    virtual Bool is_up_button_pressed() const = 0;
    virtual Bool is_down_button_pressed() const = 0;
    virtual Bool is_left_button_pressed() const = 0;
    virtual Bool is_right_button_pressed() const = 0;

    /// Action buttons.
    virtual Bool is_triangle_button_pressed() const = 0;
    virtual Bool is_circle_button_pressed() const = 0;
    virtual Bool is_cross_button_pressed() const = 0;
    virtual Bool is_square_button_pressed() const = 0;

    /// Left joystick.
    virtual Bool is_left_stick_pressed() const = 0;
    virtual Tuple<Float, Float> get_left_stick_axis() const = 0;

    /// Right joystick.
    virtual Bool is_right_stick_pressed() const = 0;
    virtual Tuple<Float, Float> get_right_stick_axis() const = 0;
};

#endif // CONTROLLER_HPP