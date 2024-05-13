#include "timer.hpp"

Timer::~Timer() {}

void Timer::setup() {}

void Timer::process(UInt p_delta)
{
    if (!is_completed() && !is_paused())
        current_time -= p_delta;
}

Bool Timer::is_completed() const
{
    return current_time < 0;
}

Bool Timer::is_paused() const
{
    return paused;
}

void Timer::set_paused(Bool p_is_paused)
{
    paused = p_is_paused;
}

void Timer::pause()
{
    paused = true;
}

void Timer::unpause()
{
    paused = false;
}

void Timer::start(Int p_duration)
{
    current_time = p_duration;
}