#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "def.hpp"
#include "component.hpp"
#include "tuple.hpp"

/// Base class for controller.
/// Controller interface is based on Dualshock 4 controller (https://manuals.playstation.net/document/en/ps4/basic/pn_controller.html).
class Controller : public Component
{
public:
private:
public:
    ~Controller() override;

    void setup() override;
    void process(UInt p_delta) override;

    /// Directional buttons.
    virtual Bool is_up_button_pressed() const;
    virtual Bool is_down_button_pressed() const;
    virtual Bool is_left_button_pressed() const;
    virtual Bool is_right_button_pressed() const;

    /// Action buttons.
    virtual Bool is_triangle_button_pressed() const;
    virtual Bool is_circle_button_pressed() const;
    virtual Bool is_cross_button_pressed() const;
    virtual Bool is_square_button_pressed() const;
    virtual Bool is_L1_button_pressed() const;
    virtual Bool is_R1_button_pressed() const;

    /// Get left joystick axis.
    /// First float is `x` axis while the second float is `y` axis.
    /// The axes must between `-1` and `1`.
    /// For `x` axis, `-1` means left while `1` means right.
    /// For `y` axis, `-1` means down while `1` means up.
    virtual Tuple<Float, Float> get_left_stick_axes() const;

    /// Get right joystick axis.
    /// First float is `x` axis while the second float is `y` axis.
    /// The axes must between `-1` and `1`.
    /// For `x` axis, `-1` means left while `1` means right.
    /// For `y` axis, `-1` means down while `1` means up.
    virtual Tuple<Float, Float> get_right_stick_axes() const;
};

#endif // CONTROLLER_HPP