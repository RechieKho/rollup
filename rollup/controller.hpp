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
    virtual ~Controller();

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

    /// Left joystick.
    virtual Bool is_left_stick_pressed() const;
    virtual Tuple<Float, Float> get_left_stick_axis() const;

    /// Right joystick.
    virtual Bool is_right_stick_pressed() const;
    virtual Tuple<Float, Float> get_right_stick_axis() const;
};

#endif // CONTROLLER_HPP