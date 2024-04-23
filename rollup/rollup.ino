#include "def.hpp"
#include "tuple.hpp"
#include "component.hpp"

Component *components[] = {/* Components here! (e.g. `new Dummy()`) */};
constexpr const UInt component_count = sizeof(components) / sizeof(Component *);

void setup()
{
  for (UInt i = 0; i < component_count; i++)
    components[i]->setup();
}

void loop()
{
  static UInt32 previous_time = millis();
  const UInt delta = UInt(millis() - previous_time);
  previous_time = millis();

  for (UInt i = 0; i < component_count; i++)
    components[i]->process(previous_time);
}