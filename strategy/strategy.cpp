#include "strategy.hpp"

#include <iostream>

void FlyWithWings::fly() const
{
    std::cout << "I'm flying!\n";
}

void FlyNoWay::fly() const
{
    std::cout << "I can't fly\n";
}

void FlyRocketPowered::fly() const
{
    std::cout << "I'm flying with a rocket!\n";
}

void Quack::quack() const
{
    std::cout << "quack!\n";
}

void Squeak::quack() const
{
    std::cout << "squeak!\n";
}

void MuteQuack::quack() const
{
    std::cout << "<< silence >>\n";
}

void Duck::swim()
{
    std::cout << "all ducks float, even decoys\n";
}

void Duck::performFly()
{
    m_flyBehavior->fly();
}

void Duck::performQuack()
{
    m_quackBehavior->quack();
}

void Duck::setFlyBehavior(std::unique_ptr<FlyBehavior> fb)
{
    m_flyBehavior = std::move(fb);
}

void Duck::setQuackBehavior(std::unique_ptr<QuackBehavior> qb)
{
    m_quackBehavior = std::move(qb);
}

MallardDuck::MallardDuck()
{
    setFlyBehavior(std::make_unique<FlyWithWings>());
    setQuackBehavior(std::make_unique<Quack>());
}

void MallardDuck::display() const
{
    std::cout << "looks like a mallard\n";
}

RubberDuck::RubberDuck()
{
    setFlyBehavior(std::make_unique<FlyNoWay>());
    setQuackBehavior(std::make_unique<Squeak>());
}

void RubberDuck::display() const
{
    std::cout << "looks like a rubber duck\n";
}

ModelDuck::ModelDuck()
{
    setFlyBehavior(std::make_unique<FlyNoWay>());
    setQuackBehavior(std::make_unique<Quack>());
}

void ModelDuck::display() const
{
    std::cout << "looks like a model duck\n";
}
