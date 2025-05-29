#include "factory-method.hpp"

std::string NyCheesePizza::getDescription() const
{
    return "New York Style Cheese Pizza";
}

std::string NyPepperoniPizza::getDescription() const
{
    return "New York Style Pepperoni Pizza";
}

std::string ChicagoCheesePizza::getDescription() const
{
    return "Chicago Style Cheese Pizza";
}

std::string ChicagoPepperoniPizza::getDescription() const
{
    return "Chicago Style Pepperoni Pizza";
}

std::unique_ptr<Pizza> PizzaStore::orderPizza(PizzaType type)
{
    auto pizza = createPizza(type);
    return pizza;
}

std::unique_ptr<Pizza> NyPizzaStore::createPizza(PizzaType type)
{
    std::unique_ptr<Pizza> pizza;
    switch (type) {
    case PizzaType::cheese:
        pizza = std::make_unique<NyCheesePizza>();
        break;
    case PizzaType::pepperoni:
        pizza = std::make_unique<NyPepperoniPizza>();
        break;
    }
    return pizza;
}

std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(PizzaType type)
{
    std::unique_ptr<Pizza> pizza;
    switch (type) {
    case PizzaType::cheese:
        pizza = std::make_unique<ChicagoCheesePizza>();
        break;
    case PizzaType::pepperoni:
        pizza = std::make_unique<ChicagoPepperoniPizza>();
        break;
    }
    return pizza;
}
