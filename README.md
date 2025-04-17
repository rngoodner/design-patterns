# design-patterns

C++ examples for the book _Head First Design Patterns 2e._ Simplified to minimal examples and adapted to C++ conventions.

## Strategy Pattern

The Strategy Pattern defines a family of algorithms,
encapsulates each one, and makes them interchangeable.
Strategy lets the algorithm vary independently from
clients that use it.

```mermaid
classDiagram

class QuackBehavior {
    public virtual ~QuackBehavior() = default;
    public virtual void quack() const = 0;
}

class Quack {
    public void quack() const override
}

class Squeak {
    public void quack() const override
}

class Duck {
    public virtual ~Duck() = default
    public virtual void display() const = 0

    public void performQuack()
    public void setQuack(std::unique_ptr__QuackBehavior qb)

    private std::unique_ptr__QuackBehavior m_quackBehavior
}

class MallardDuck {
    public MallardDuck()
    public void display() const override
}

class RubberDuck {
    public RubberDuck()
    public void display() const override
}

Duck <|.. RubberDuck
Duck <|.. MallardDuck
Duck --> QuackBehavior
QuackBehavior <|.. Quack
QuackBehavior <|.. Squeak
```