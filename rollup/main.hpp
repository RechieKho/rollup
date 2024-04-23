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
    ~Main() override final = default;

    void setup() override final;
    void process(UInt p_delta) override final;
};

#endif // MAIN_HPP