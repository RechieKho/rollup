#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "def.hpp"

/// Abstract class for component.
class Component
{
public:
private:
public:
    /// Virtual class.
    virtual ~Component() = 0;

    /// To be called in `setup`.
    virtual void setup() = 0;

    /// To be called in `loop`.
    /// `p_delta` is the time elapsed between calls in milliseconds.
    virtual void process(UInt p_delta) = 0;
};

#endif // COMPONENT_HPP