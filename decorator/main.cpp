#include "decorator.hpp"

#include <iomanip>
#include <iostream>
#include <memory>

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    // espresso — no condiments
    std::shared_ptr<Beverage> b1 = std::make_shared<Espresso>();
    std::cout << b1->getDescription() << " $" << b1->cost() << "\n";

    // dark roast with two mochas and a whip — each decorator adds to description and cost
    std::shared_ptr<Beverage> b2 = std::make_shared<DarkRoast>();
    b2 = std::make_shared<Mocha>(b2);
    b2 = std::make_shared<Mocha>(b2);
    b2 = std::make_shared<Whip>(b2);
    std::cout << b2->getDescription() << " $" << b2->cost() << "\n";

    // house blend with soy, mocha, and whip
    std::shared_ptr<Beverage> b3 = std::make_shared<HouseBlend>();
    b3 = std::make_shared<Soy>(b3);
    b3 = std::make_shared<Mocha>(b3);
    b3 = std::make_shared<Whip>(b3);
    std::cout << b3->getDescription() << " $" << b3->cost() << "\n";
}
