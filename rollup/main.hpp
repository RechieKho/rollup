#ifndef MAIN_HPP
#define MAIN_HPP

#include "def.hpp"
#include "component.hpp"
#include "controller.hpp"
#include "motion.hpp"

/// Main loop.
class Main : public Component
{
public:
private:
    Controller *controller;
    Motion *motion;

public:
    Main(Controller *p_controller = nullptr, Motion *p_motion = nullptr);
    ~Main() override final;

    void setup() override final;
    void process(UInt p_delta) override final;
};

#endif // MAIN_HPP