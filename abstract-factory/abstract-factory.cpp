#include "abstract-factory.hpp"

#include <cstddef>
#include <iostream>
#include <string>

using namespace af;

CheesePizza::CheesePizza(PizzaIngredientFactory& factory)
    : m_factory(factory)
{
}

PepperoniPizza::PepperoniPizza(PizzaIngredientFactory& factory)
    : m_factory(factory)
{
}

std::string NyIngredientFactory::createDough() const
{
    return std::string("Thin Crust Dough");
}

std::string NyIngredientFactory::createSauce() const
{
    return std::string("Marinara Sauce");
}

std::string ChicagoIngredientFactory::createDough() const
{
    return std::string("Thick Crust Dough");
}

std::string ChicagoIngredientFactory::createSauce() const
{
    return std::string("Plum Tomato Sauce");
}

std::string CheesePizza::getDescription() const
{
    return "Cheese Pizza with " + m_factory.createSauce() + " and " + m_factory.createDough();
}

std::string PepperoniPizza::getDescription() const
{
    return "Pepperoni Pizza with " + m_factory.createSauce() + " and " + m_factory.createDough();
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
        pizza = std::make_unique<CheesePizza>(*m_factory);
        break;
    case PizzaType::pepperoni:
        pizza = std::make_unique<PepperoniPizza>(*m_factory);
        break;
    }
    return pizza;
}

std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(PizzaType type)
{
    std::unique_ptr<Pizza> pizza;
    switch (type) {
    case PizzaType::cheese:
        pizza = std::make_unique<CheesePizza>(*m_factory);
        break;
    case PizzaType::pepperoni:
        pizza = std::make_unique<PepperoniPizza>(*m_factory);
        break;
    }
    return pizza;
}
