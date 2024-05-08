#include "motion.hpp"

Motion::~Motion() {}

void Motion::setup() {}
void Motion::process(UInt p_delta) {}

Int16 Motion::get_velocity() const { return 0; }
Int16 Motion::get_angular_velocity() const { return 0; }
void Motion::set_velocity(Int16 p_velocity) {}
void Motion::set_angular_velocity(Int16 p_angular_velocity) {}