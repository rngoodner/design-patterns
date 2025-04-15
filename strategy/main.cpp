#include <iostream>
#include <memory>

class QuackBehavior {
public:
    virtual ~QuackBehavior() = default;
    virtual void quack() const = 0;
};

class Quack : public QuackBehavior {
public:
    void quack() const override
    {
        std::cout << "quack!\n";
    };
};

class Squeak : public QuackBehavior {
public:
    void quack() const override
    {
        std::cout << "squeak!\n";
    };
};

class MuteQuack : public QuackBehavior {
public:
    void quack() const override
    {
        std::cout << "...\n";
    };
};

class Duck {
public:
    virtual ~Duck() = default;

    virtual void display() const = 0;

    void performQuack()
    {
        m_quackBehavior->quack();
    }

    void setQuack(std::unique_ptr<QuackBehavior> qb)
    {
        m_quackBehavior = std::move(qb);
    }

private:
    // duck HAS-A QuackBehavior; prefer Composition over Inheritance
    std::unique_ptr<QuackBehavior> m_quackBehavior;
};

class MallardDuck : public Duck {
public:
    MallardDuck()
    {
        setQuack(std::make_unique<Quack>());
    }

    void display() const override
    {
        std::cout << "looks like a mallard\n";
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck()
    {
        setQuack(std::make_unique<Squeak>());
    }

    void display() const override
    {
        std::cout << "looks like a rubber duckie\n";
    }
};

class DecoyDuck : public Duck {
public:
    DecoyDuck()
    {
        setQuack(std::make_unique<MuteQuack>());
    }

    void display() const override
    {
        std::cout << "looks like a decoy\n";
    }
};

int main()
{
    // program to the interface, not the implementation
    std::unique_ptr<Duck> mallard = std::make_unique<MallardDuck>();
    std::unique_ptr<Duck> rubberDuckie = std::make_unique<RubberDuck>();
    std::unique_ptr<Duck> decoy = std::make_unique<DecoyDuck>();

    // each has unique behavior
    mallard->display();
    mallard->performQuack();
    rubberDuckie->display();
    rubberDuckie->performQuack();
    decoy->display();
    decoy->performQuack();

    // can change behavior at runtime
    decoy->setQuack(std::make_unique<Quack>());
    decoy->display();
    decoy->performQuack();
}