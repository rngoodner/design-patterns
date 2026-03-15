#include "state.hpp"

#include <cstdlib>

int main()
{
    std::srand(42); // fixed seed for reproducible output

    GumballMachine machine { 5 };
    machine.print();

    machine.insertQuarter();
    machine.turnCrank();
    machine.print();

    machine.insertQuarter();
    machine.ejectQuarter();

    machine.insertQuarter();
    machine.turnCrank();
    machine.print();

    // force winner state to demonstrate it — seed 42 triggers winner on this roll
    machine.insertQuarter();
    machine.turnCrank();
    machine.print();
}
