#include "state.hpp"

#include <iostream>

// GumballMachine

GumballMachine::GumballMachine(int count, unsigned seed)
    : m_noQuarterState(*this)
    , m_hasQuarterState(*this)
    , m_soldState(*this)
    , m_winnerState(*this)
    , m_soldOutState()
    , m_rng(seed)
    , m_currentState(count > 0 ? static_cast<State*>(&m_noQuarterState) : &m_soldOutState)
    , m_count(count)
{
}

void GumballMachine::insertQuarter() { m_currentState->insertQuarter(); }
void GumballMachine::ejectQuarter() { m_currentState->ejectQuarter(); }

void GumballMachine::turnCrank()
{
    m_currentState->turnCrank();
    m_currentState->dispense();
}

void GumballMachine::releaseBall()
{
    if (m_count > 0) {
        std::cout << "A gumball rolls out\n";
        --m_count;
    }
}

int GumballMachine::getCount() const { return m_count; }
void GumballMachine::setState(State& state) { m_currentState = &state; }

void GumballMachine::print() const
{
    std::cout << "Gumball machine: " << m_count << " gumball" << (m_count != 1 ? "s" : "") << " remaining\n";
}

State& GumballMachine::getNoQuarterState() { return m_noQuarterState; }
State& GumballMachine::getHasQuarterState() { return m_hasQuarterState; }
State& GumballMachine::getSoldState() { return m_soldState; }
State& GumballMachine::getWinnerState() { return m_winnerState; }
State& GumballMachine::getSoldOutState() { return m_soldOutState; }

// NoQuarterState

NoQuarterState::NoQuarterState(GumballMachine& machine)
    : m_machine(machine)
{
}

void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted a quarter\n";
    m_machine.setState(m_machine.getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
    std::cout << "You haven't inserted a quarter\n";
}

void NoQuarterState::turnCrank()
{
    std::cout << "You turned but there's no quarter\n";
}

void NoQuarterState::dispense()
{
    std::cout << "You need to pay first\n";
}

// HasQuarterState

HasQuarterState::HasQuarterState(GumballMachine& machine)
    : m_machine(machine)
{
}

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter\n";
}

void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned\n";
    m_machine.setState(m_machine.getNoQuarterState());
}

void HasQuarterState::turnCrank()
{
    std::cout << "You turned...\n";
    // 1-in-10 chance of winning two gumballs
    if (m_machine.m_rng() % 10 == 0 && m_machine.getCount() > 1)
        m_machine.setState(m_machine.getWinnerState());
    else
        m_machine.setState(m_machine.getSoldState());
}

void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed\n";
}

// SoldState

SoldState::SoldState(GumballMachine& machine)
    : m_machine(machine)
{
}

void SoldState::insertQuarter()
{
    std::cout << "Please wait, we're already giving you a gumball\n";
}

void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank\n";
}

void SoldState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball\n";
}

void SoldState::dispense()
{
    m_machine.releaseBall();
    if (m_machine.getCount() > 0)
        m_machine.setState(m_machine.getNoQuarterState());
    else {
        std::cout << "Out of gumballs!\n";
        m_machine.setState(m_machine.getSoldOutState());
    }
}

// WinnerState

WinnerState::WinnerState(GumballMachine& machine)
    : m_machine(machine)
{
}

void WinnerState::insertQuarter()
{
    std::cout << "Please wait, we're already giving you a gumball\n";
}

void WinnerState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank\n";
}

void WinnerState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball\n";
}

void WinnerState::dispense()
{
    std::cout << "You're a winner! You get two gumballs for your quarter\n";
    m_machine.releaseBall();
    if (m_machine.getCount() > 0) {
        m_machine.releaseBall();
        if (m_machine.getCount() > 0)
            m_machine.setState(m_machine.getNoQuarterState());
        else {
            std::cout << "Out of gumballs!\n";
            m_machine.setState(m_machine.getSoldOutState());
        }
    } else {
        std::cout << "Out of gumballs!\n";
        m_machine.setState(m_machine.getSoldOutState());
    }
}

// SoldOutState

void SoldOutState::insertQuarter()
{
    std::cout << "Machine is sold out\n";
}

void SoldOutState::ejectQuarter()
{
    std::cout << "You can't eject, you haven't inserted a quarter yet\n";
}

void SoldOutState::turnCrank()
{
    std::cout << "Machine is sold out\n";
}

void SoldOutState::dispense()
{
    std::cout << "No gumball dispensed\n";
}
