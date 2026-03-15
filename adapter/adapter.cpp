#include "adapter.hpp"

#include <iostream>

void GreenHeadDuck::quack() const
{
    std::cout << "quack!\n";
}

void GreenHeadDuck::fly() const
{
    std::cout << "I'm flying\n";
}

void WildTurkey::gobble() const
{
    std::cout << "gobble gobble\n";
}

void WildTurkey::fly() const
{
    std::cout << "I'm flying a short distance\n";
}

TurkeyAdapter::TurkeyAdapter(Turkey& turkey)
    : m_turkey(turkey)
{
}

void TurkeyAdapter::quack() const
{
    // adapt Turkey's gobble() to Duck's quack() interface
    m_turkey.gobble();
}

void TurkeyAdapter::fly() const
{
    // turkeys fly short distances; call multiple times to simulate duck flight
    m_turkey.fly();
    m_turkey.fly();
}
