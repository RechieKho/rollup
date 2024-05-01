#ifndef DUMMY_MOTION_HPP
#define DUMMY_MOTION_HPP

#include "def.hpp"
#include "motion.hpp"

class DummyMotion : public Motion {
public:
private:
  Int8 velocity;

public:
  Int8 get_velocity() const override;
  void set_velocity(Int8 p_veloctiy) override;
};

#endif