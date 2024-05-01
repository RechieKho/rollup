#ifndef DUMMY_MOTION_HPP
#define DUMMY_MOTION_HPP

#include "def.hpp"
#include "motion.hpp"

class DummyMotion : public Motion {
public:
private:
  Int8 velocity;

public:
  void set_velocity(Int8 p_veloctiy) override;
};

#endif