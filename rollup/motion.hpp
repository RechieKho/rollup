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
    virtual void set_velocity(Int8 p_veloctiy) = 0;

    /// Set the rotation.
    virtual void set_rotation(Int16 p_degree) = 0;
};

#endif // MOTION_HPP