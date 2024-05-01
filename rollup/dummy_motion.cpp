#include "dummy_motion.hpp"

void DummyMotion::set_velocity(Int8 p_velocity) {
  velocity = p_velocity;
}

Int8 DummyMotion::get_velocity() const {
  return velocity;
}