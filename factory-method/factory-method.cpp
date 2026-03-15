#include "factory-method.hpp"

#include <iostream>

// Pizza lifecycle — shared by all pizza types; concrete classes provide getName()

void Pizza::prepare()
{
    std::cout << "Preparing " << getName() << "\n";
    std::cout << "  Tossing dough...\n";
    std::cout << "  Adding sauce...\n";
    std::cout << "  Adding toppings...\n";
}

void Pizza::bake()
{
    std::cout << "Baking for 25 minutes at 350\n";
}

void Pizza::cut()
{
    doCut();
}

void Pizza::doCut()
{
    std::cout << "Cutting pizza into diagonal slices\n";
}

void Pizza::box()
{
    std::cout << "Placing pizza in official PizzaStore box\n";
}

// NY pizza names

std::string NyCheesePizza::getName() const { return "New York Style Sauce and Cheese Pizza"; }
std::string NyVeggiePizza::getName() const { return "New York Style Veggie Pizza"; }
std::string NyClamPizza::getName() const { return "New York Style Clam Pizza"; }
std::string NyPepperoniPizza::getName() const { return "New York Style Pepperoni Pizza"; }

// Chicago pizza names and square-cut override

std::string ChicagoCheesePizza::getName() const { return "Chicago Style Deep Dish Cheese Pizza"; }
std::string ChicagoVeggiePizza::getName() const { return "Chicago Style Deep Dish Veggie Pizza"; }
std::string ChicagoClamPizza::getName() const { return "Chicago Style Deep Dish Clam Pizza"; }
std::string ChicagoPepperoniPizza::getName() const { return "Chicago Style Deep Dish Pepperoni Pizza"; }

void ChicagoCheesePizza::doCut() { std::cout << "Cutting pizza into square slices\n"; }
void ChicagoVeggiePizza::doCut() { std::cout << "Cutting pizza into square slices\n"; }
void ChicagoClamPizza::doCut() { std::cout << "Cutting pizza into square slices\n"; }
void ChicagoPepperoniPizza::doCut() { std::cout << "Cutting pizza into square slices\n"; }

// PizzaStore — orderPizza() controls the lifecycle; createPizza() is the factory method

std::unique_ptr<Pizza> PizzaStore::orderPizza(PizzaType type)
{
    auto pizza = createPizza(type);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
}

std::unique_ptr<Pizza> NyPizzaStore::createPizza(PizzaType type)
{
    switch (type) {
    case PizzaType::cheese:
        return std::make_unique<NyCheesePizza>();
    case PizzaType::veggie:
        return std::make_unique<NyVeggiePizza>();
    case PizzaType::clam:
        return std::make_unique<NyClamPizza>();
    case PizzaType::pepperoni:
        return std::make_unique<NyPepperoniPizza>();
    }
    return nullptr;
}

std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(PizzaType type)
{
    switch (type) {
    case PizzaType::cheese:
        return std::make_unique<ChicagoCheesePizza>();
    case PizzaType::veggie:
        return std::make_unique<ChicagoVeggiePizza>();
    case PizzaType::clam:
        return std::make_unique<ChicagoClamPizza>();
    case PizzaType::pepperoni:
        return std::make_unique<ChicagoPepperoniPizza>();
    }
    return nullptr;
}
