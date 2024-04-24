#include "motion.hpp"

Motion::~Motion() {}

void Motion::setup() {}
void Motion::process(UInt p_delta) {}

Int8 Motion::get_velocity() const { return 0; }
Int8 Motion::get_angular_velocity() const { return 0; }
void Motion::set_velocity(Int8 p_velocity) {}
void Motion::set_angular_velocity(Int8 p_degree) {}