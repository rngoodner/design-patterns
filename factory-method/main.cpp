#include "factory-method.hpp"

#include <iostream>

int main()
{
    NyPizzaStore nyStore;
    ChicagoPizzaStore chicagoStore;

    // orderPizza() runs the full lifecycle; createPizza() (the factory method) decides the type
    auto pizza = nyStore.orderPizza(PizzaType::cheese);
    std::cout << "Ethan ordered a " << pizza->getName() << "\n\n";

    pizza = chicagoStore.orderPizza(PizzaType::cheese);
    std::cout << "Joel ordered a " << pizza->getName() << "\n";
}
