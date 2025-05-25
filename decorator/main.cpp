#include "decorator.hpp"

#include <iostream>
#include <memory>

int main()
{
    // Make a coffee with soy, sugar, and whip
    std::shared_ptr<Beverage> coffee = std::make_shared<Coffee>();
    coffee = std::make_shared<Soy>(coffee);
    coffee = std::make_shared<Sugar>(coffee);
    coffee = std::make_shared<Whip>(coffee);
    std::cout << coffee->getDescription() << std::endl;

    // Make a tea with milk and sugar
    std::shared_ptr<Beverage> tea = std::make_shared<Tea>();
    tea = std::make_shared<Milk>(tea);
    tea = std::make_shared<Sugar>(tea);
    std::cout << tea->getDescription() << std::endl;

    return 0;
}
