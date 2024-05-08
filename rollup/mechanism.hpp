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
    virtual void capture();
    /// Send the ball to heigher position.
    virtual void prepare();
    /// Send the ball to the lower position.
    virtual void unprepare();
    /// Release the ball.
    virtual void dispatch();
};

#endif // MECHANISM_HPP