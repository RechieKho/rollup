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
    /// Prepare to capture ball.
    virtual void prepare_capture();
    /// Capturing the ball in front.
    virtual void capture();
    /// Prepare to dispatch ball.
    virtual void prepare_dispatch();
    /// Dispatch the ball.
    virtual void dispatch();
    /// Revert the dispatch.
    virtual void revert_dispatch();
};

#endif // MECHANISM_HPP