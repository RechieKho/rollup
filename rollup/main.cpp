#include "main.hpp"

constexpr const Int8 VELOCITY_MAGNITUDE = 128;
constexpr const Int8 ANGULAR_VELOCITY_MAGNITUDE = 64;

static inline UInt8 as_axis(Bool p_negative, Bool p_positive)
{
    return (p_positive ? 1 : 0) - (p_negative ? 1 : 0);
}

Main::Main(Controller *p_controller, Motion *p_motion)
    : controller(p_controller ? p_controller : new Controller()), motion(p_motion ? p_motion : new Motion()) {}

Main::~Main()
{
    if (controller)
        delete controller;
    if (motion)
        delete motion;
}

void Main::setup()
{
    controller->setup();
    motion->setup();
}

void Main::process(UInt p_delta)
{
    controller->process(p_delta);
    motion->process(p_delta);

    const UInt8 x = as_axis(controller->is_left_button_pressed(), controller->is_right_button_pressed());
    const UInt8 y = as_axis(controller->is_down_button_pressed(), controller->is_up_button_pressed());

    motion->set_angular_velocity(x * ANGULAR_VELOCITY_MAGNITUDE);
    motion->set_velocity(y * VELOCITY_MAGNITUDE);
}