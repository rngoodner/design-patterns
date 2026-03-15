#include "abstract-factory.hpp"

#include <iostream>

using namespace af;

int main()
{
    NyPizzaStore nyStore;
    ChicagoPizzaStore chicagoStore;

    // same pizza type, different ingredients — the factory determines regional variation
    auto pizza = nyStore.orderPizza(PizzaType::cheese);
    std::cout << "Ethan ordered a " << pizza->getName() << "\n\n";

    pizza = chicagoStore.orderPizza(PizzaType::cheese);
    std::cout << "Joel ordered a " << pizza->getName() << "\n";
}
