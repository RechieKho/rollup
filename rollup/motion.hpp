#ifndef MOTION_HPP
#define MOTION_HPP

#include "def.hpp"
#include "component.hpp"

/// Abstract class for locomotion.
class Motion : public Component
{
public:
private:
public:
    /// Virtual class.
    virtual ~Motion() = 0;

    /// Set the velocity.
    /// When `p_velocity > 0`, move forward.
    /// When `p_velocity == 0`, stop moving.
    /// When `p_velocity < 0`, move backward.
    virtual void set_velocity(Int8 p_veloctiy) = 0;

    /// Set the angular velocity.
    /// When `p_degree > 0`, rotate to right.
    /// When `p_degree == 0`, rotate to left.
    /// When `p_degree < 0`, rotate to left.
    virtual void set_angular_velocity(Int8 p_degree) = 0;
};

#endif // MOTION_HPP