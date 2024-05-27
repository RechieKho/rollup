#include "main.hpp"

#include <Arduino.h>

#define VELOCITY_MAGNITUDE INT8_MAX
#define ANGULAR_VELOCITY_MAGNITUDE INT8_MAX

Main::Main(Controller *p_controller, Motion *p_motion, Mechanism *p_mechanism)
    : controller(p_controller ? p_controller : new Controller()),
      motion(p_motion ? p_motion : new Motion()),
      mechanism(p_mechanism ? p_mechanism : new Mechanism()) {}

Main::~Main()
{
    if (controller)
        delete controller;
    if (motion)
        delete motion;
    if (mechanism)
        delete mechanism;
}

void Main::setup()
{
    controller->setup();
    motion->setup();
    mechanism->setup();
}

void Main::process(UInt p_delta)
{
    controller->process(p_delta);
    motion->process(p_delta);
    mechanism->process(p_delta);

    const auto x = (Int8)(controller->is_right_button_pressed() - controller->is_left_button_pressed());
    const auto y = (Int8)(controller->is_up_button_pressed() - controller->is_down_button_pressed());

    motion->set_angular_velocity(x * ANGULAR_VELOCITY_MAGNITUDE);
    motion->set_velocity(y * VELOCITY_MAGNITUDE);

    if (controller->is_circle_button_pressed())
        mechanism->capture();
    else if (controller->is_cross_button_pressed())
        mechanism->dispatch();
    else if (controller->is_triangle_button_pressed())
        mechanism->prepare_capture();
    else if (controller->is_square_button_pressed())
        mechanism->prepare_dispatch();
    else if (controller->is_R1_button_pressed())
        mechanism->revert_dispatch();
}