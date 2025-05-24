#include "strategy.hpp"

#include <iostream>

void Quack::quack() const
{
    std::cout << "quack!\n";
}

void Squeak::quack() const
{
    std::cout << "squeak!\n";
}

void Duck::performQuack()
{
    m_quackBehavior->quack();
}

void Duck::setQuack(std::unique_ptr<QuackBehavior> qb)
{
    m_quackBehavior = std::move(qb);
}

MallardDuck::MallardDuck()
{
    setQuack(std::make_unique<Quack>());
}

void MallardDuck::display() const
{
    std::cout << "looks like a mallard\n";
}

RubberDuck::RubberDuck()
{
    setQuack(std::make_unique<Squeak>());
}

void RubberDuck::display() const
{
    std::cout << "looks like a rubber duckie\n";
}
