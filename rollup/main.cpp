#include "main.hpp"

constexpr const Int8 VELOCITY_MAGNITUDE = 128;
constexpr const Int8 ANGULAR_VELOCITY_MAGNITUDE = 64;

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

    const auto axes = controller->get_left_stick_axes();
    const auto x = axes.get<0>();
    const auto y = axes.get<1>();

    motion->set_angular_velocity(x * ANGULAR_VELOCITY_MAGNITUDE);
    motion->set_velocity(y * VELOCITY_MAGNITUDE);

    if (controller->is_circle_button_pressed())
        mechanism->capture();
    else if (controller->is_cross_button_pressed())
        mechanism->dispatch();
    else if (controller->is_triangle_button_pressed())
        mechanism->prepare();
    else if (controller->is_square_button_pressed())
        mechanism->unprepare();
}