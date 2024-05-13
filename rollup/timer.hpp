#ifndef TIMER_HPP
#define TIMER_HPP

#include "def.hpp"
#include "component.hpp"

class Timer : public Component
{
public:
private:
    Int current_time;
    Bool paused;

public:
    ~Timer() override;

    void setup() override;
    void process(UInt p_delta) override;

    Bool is_completed() const;
    Bool is_paused() const;
    void set_paused(Bool p_is_paused);
    void pause();
    void unpause();
    void start(Int p_duration = 1000);
};

#endif // TIMER_HPP