#include "abstract-factory.hpp"

#include <iostream>

using namespace af;

int main()
{
    // create two different pizza stores
    std::unique_ptr<PizzaStore> nyStore = std::make_unique<NyPizzaStore>();
    std::unique_ptr<PizzaStore> chicagoStore = std::make_unique<ChicagoPizzaStore>();

    // oreder pizzas from the ny store
    auto nyCheese = nyStore->orderPizza(PizzaType::cheese);
    std::cout << "Received a " << nyCheese->getDescription() << std::endl;
    auto nyPepperoni = nyStore->orderPizza(PizzaType::pepperoni);
    std::cout << "Received a " << nyPepperoni->getDescription() << std::endl;

    // oreder pizzas from the chicago store
    auto chicagoCheese = chicagoStore->orderPizza(PizzaType::cheese);
    std::cout << "Received a " << chicagoCheese->getDescription() << std::endl;
    auto chicagoPepperoni = chicagoStore->orderPizza(PizzaType::pepperoni);
    std::cout << "Received a " << chicagoPepperoni->getDescription() << std::endl;

    return 0;
}
