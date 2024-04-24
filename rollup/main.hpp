#ifndef MAIN_HPP
#define MAIN_HPP

#include "def.hpp"
#include "component.hpp"
#include "controller.hpp"
#include "motion.hpp"
#include "mechanism.hpp"

/// Main loop.
class Main final : public Component
{
public:
private:
    Controller *controller;
    Motion *motion;
    Mechanism *mechanism;

public:
    Main(Controller *p_controller = nullptr, Motion *p_motion = nullptr, Mechanism *p_mechanism = nullptr);
    ~Main() override final;

    void setup() override final;
    void process(UInt p_delta) override final;
};

#endif // MAIN_HPP