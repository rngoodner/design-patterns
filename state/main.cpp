#include "state.hpp"

int main()
{
    GumballMachine machine { 5 }; // default seed guarantees winner on the last crank
    machine.print();

    machine.insertQuarter();
    machine.turnCrank();
    machine.print();

    machine.insertQuarter();
    machine.ejectQuarter();

    machine.insertQuarter();
    machine.turnCrank();
    machine.print();

    machine.insertQuarter();
    machine.turnCrank();
    machine.print();
}
