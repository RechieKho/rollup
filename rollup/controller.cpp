#include "controller.hpp"

Controller::~Controller() {}

void Controller::setup() {}
void Controller::process(UInt p_delta) {}

Bool Controller::is_up_button_pressed() const { return false; }
Bool Controller::is_down_button_pressed() const { return false; }
Bool Controller::is_left_button_pressed() const { return false; }
Bool Controller::is_right_button_pressed() const { return false; }

Bool Controller::is_triangle_button_pressed() const { return false; }
Bool Controller::is_circle_button_pressed() const { return false; }
Bool Controller::is_cross_button_pressed() const { return false; }
Bool Controller::is_square_button_pressed() const { return false; }

Bool Controller::is_left_stick_pressed() const { return false; }
Tuple<Float, Float> Controller::get_left_stick_axes() const { return Tuple<Float, Float>(0, 0); }

Bool Controller::is_right_stick_pressed() const { return false; }
Tuple<Float, Float> Controller::get_right_stick_axes() const { return Tuple<Float, Float>(0, 0); }