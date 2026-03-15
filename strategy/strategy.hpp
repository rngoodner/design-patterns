#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <memory>

// FlyBehavior strategy interface
class FlyBehavior {
public:
    virtual ~FlyBehavior() = default;
    virtual void fly() const = 0;
};

// Concrete fly strategies
class FlyWithWings : public FlyBehavior {
public:
    void fly() const override;
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() const override;
};

class FlyRocketPowered : public FlyBehavior {
public:
    void fly() const override;
};

// QuackBehavior strategy interface
class QuackBehavior {
public:
    virtual ~QuackBehavior() = default;
    virtual void quack() const = 0;
};

// Concrete quack strategies
class Quack : public QuackBehavior {
public:
    void quack() const override;
};

class Squeak : public QuackBehavior {
public:
    void quack() const override;
};

class MuteQuack : public QuackBehavior {
public:
    void quack() const override;
};

// Duck interface — HAS-A FlyBehavior and HAS-A QuackBehavior (composition over inheritance)
class Duck {
public:
    virtual ~Duck() = default;

    virtual void display() const = 0;
    void swim();
    void performFly();
    void performQuack();
    void setFlyBehavior(std::unique_ptr<FlyBehavior> fb);
    void setQuackBehavior(std::unique_ptr<QuackBehavior> qb);

private:
    std::unique_ptr<FlyBehavior> m_flyBehavior;
    std::unique_ptr<QuackBehavior> m_quackBehavior;
};

// Concrete duck types
class MallardDuck : public Duck {
public:
    MallardDuck();
    void display() const override;
};

class RubberDuck : public Duck {
public:
    RubberDuck();
    void display() const override;
};

// ModelDuck starts with FlyNoWay; demonstrates runtime behavior swap
class ModelDuck : public Duck {
public:
    ModelDuck();
    void display() const override;
};

#endif // STRATEGY_HPP
