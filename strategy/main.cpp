#include "strategy.hpp"

int main()
{
    // program to the interface, not the implementation
    std::unique_ptr<Duck> mallard = std::make_unique<MallardDuck>();
    std::unique_ptr<Duck> rubberDuckie = std::make_unique<RubberDuck>();

    // each has unique behavior
    mallard->display();
    mallard->performQuack();
    rubberDuckie->display();
    rubberDuckie->performQuack();

    // can change behavior at runtime
    rubberDuckie->setQuack(std::make_unique<Quack>());
    rubberDuckie->display();
    rubberDuckie->performQuack();
}