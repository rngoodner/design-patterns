#include "adapter.hpp"

#include <iostream>
#include <memory>

void testDuck(const Duck& duck)
{
    duck.quack();
    duck.fly();
}

int main()
{
    GreenHeadDuck duck;
    WildTurkey turkey;

    // TurkeyAdapter wraps a Turkey so it can be used anywhere a Duck is expected
    std::unique_ptr<Duck> turkeyAdapter = std::make_unique<TurkeyAdapter>(turkey);

    std::cout << "GreenHeadDuck:\n";
    testDuck(duck);

    std::cout << "TurkeyAdapter:\n";
    testDuck(*turkeyAdapter);
}
