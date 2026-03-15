#include "strategy.hpp"

int main()
{
    MallardDuck mallard;
    mallard.display();
    mallard.performQuack();
    mallard.performFly();

    // model duck starts unable to fly; swap to rocket-powered at runtime
    ModelDuck model;
    model.display();
    model.performFly();
    model.setFlyBehavior(std::make_unique<FlyRocketPowered>());
    model.performFly();
}
