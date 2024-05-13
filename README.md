# Rollup

Blazingly-fast arduino robot for Robotsprint,
heavily inspired from [SJTU VEX](https://www.youtube.com/watch?v=_HBTQAAVvzM).

## Dependency

- [PsxNewLib](https://www.arduino.cc/reference/en/libraries/psxnewlib/)

## Source files overview

This project strictly obey [single-responsibility principle](https://en.wikipedia.org/wiki/Single-responsibility_principle), in which each source having one and only responsibility.

Below shows the table for the responsibility of each source.

| Source                             | Responsibility                                                                                 |
| ---------------------------------- | ---------------------------------------------------------------------------------------------- |
| `def.hpp`                          | Definitions and utilities.                                                                     |
| `tuple.hpp`                        | Compile-time set of data.                                                                      |
| `rollup.ino`                       | Main entry point.                                                                              |
| `main.hpp`, `main.cpp`             | Main program, where the main components interact with each other.                              |
| `component.hpp`, `component.cpp`   | `Component` interface, to assure the inherited class having `setup` and `process` implemented. |
| `mechanism.hpp`, `mechanism.cpp`   | `Mechanism` interface, to assure the inherited class handles robot's mechanism.                |
| `motion.hpp`, `motion.cpp`         | `Motion` interface, to assure the inherited class handles robot's locomotion.                  |
| `controller.hpp`, `controller.cpp` | `Controller` interface, to assure the inherited class handles controller input.                |
| `timer.hpp`, `timer.cpp`           | A `Component` that is a timer.                                                                 |
| `MG995.hpp`                        | A `Component` that controls MG995 servo motor.                                                 |
| `BTS7960.hpp`                      | A `Component` that controls BTS7960 motor driver.                                              |
| `relay.hpp`                        | A `Component` that handles relay circuit.                                                      |
| `roller_mechanism.hpp`             | A `Mechanism` uses a roller.                                                                   |
| `PS2_controller.hpp`               | A `Controller` that uses `PsxNewLib`.                                                          |
| `L298N.hpp`                        | A `Component` that controls L298N motor driver.                                                |
| `L298_motion.hpp`                  | A `Motion` that uses `L298N`.                                                                  |
