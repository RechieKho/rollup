#ifndef MECHANISM_HPP
#define MECHANISM_HPP

#include "def.hpp"
#include "component.hpp"

/// Base class for mechanism
class Mechanism : public Component
{
public:
private:
public:
    ~Mechanism() override;

    void setup() override;
    void process(UInt p_delta) override;

    /// Actions.
    /// Capturing the ball in front.
    virtual void capture_ball();
    /// Send the ball to heigher position.
    virtual void mount_ball();
    /// Send the ball to the lower position.
    virtual void unmount_ball();
    /// Release the ball.
    virtual void dispatch_ball();
};

#endif // MECHANISM_HPP