#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <memory>

// QuackBehavior strategy interface
class QuackBehavior {
public:
    virtual ~QuackBehavior() = default;
    virtual void quack() const = 0;
};

// Concrete strategies
class Quack : public QuackBehavior {
public:
    void quack() const override;
};

class Squeak : public QuackBehavior {
public:
    void quack() const override;
};

// Duck interface that uses a strategy
class Duck {
public:
    virtual ~Duck() = default;

    virtual void display() const = 0;
    void performQuack();
    void setQuack(std::unique_ptr<QuackBehavior> qb);

private:
    // duck HAS-A QuackBehavior; prefer Composition over Inheritance
    std::unique_ptr<QuackBehavior> m_quackBehavior;
};

// MallardDuck is a concrete Duck class
class MallardDuck : public Duck {
public:
    MallardDuck();
    void display() const override;
};

// RubberDuck is a concrete Duck class
class RubberDuck : public Duck {
public:
    RubberDuck();
    void display() const override;
};

#endif // STRATEGY_HPP
