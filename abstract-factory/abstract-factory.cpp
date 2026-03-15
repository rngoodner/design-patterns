#include "abstract-factory.hpp"

#include <iostream>

using namespace af;

// NY ingredient factory — thin crust, fresh regional ingredients

std::string NyIngredientFactory::createDough() const { return "Thin Crust Dough"; }
std::string NyIngredientFactory::createSauce() const { return "Marinara Sauce"; }
std::string NyIngredientFactory::createCheese() const { return "Reggiano Cheese"; }
std::string NyIngredientFactory::createClam() const { return "Fresh Clams"; }

// Chicago ingredient factory — thick crust, hearty regional ingredients

std::string ChicagoIngredientFactory::createDough() const { return "Thick Crust Dough"; }
std::string ChicagoIngredientFactory::createSauce() const { return "Plum Tomato Sauce"; }
std::string ChicagoIngredientFactory::createCheese() const { return "Shredded Mozzarella Cheese"; }
std::string ChicagoIngredientFactory::createClam() const { return "Frozen Clams"; }

// Pizza lifecycle — shared steps

void Pizza::bake()
{
    std::cout << "Baking for 25 minutes at 350\n";
}

void Pizza::cut()
{
    std::cout << "Cutting pizza into diagonal slices\n";
}

void Pizza::box()
{
    std::cout << "Placing pizza in official PizzaStore box\n";
}

// CheesePizza — prepare() pulls ingredients from whichever factory was injected

CheesePizza::CheesePizza(PizzaIngredientFactory& factory)
    : m_factory(factory)
{
}

std::string CheesePizza::getName() const { return "Cheese Pizza"; }

void CheesePizza::prepare()
{
    std::cout << "Preparing " << getName() << "\n";
    std::cout << "  Dough: " << m_factory.createDough() << "\n";
    std::cout << "  Sauce: " << m_factory.createSauce() << "\n";
    std::cout << "  Cheese: " << m_factory.createCheese() << "\n";
}

// ClamPizza

ClamPizza::ClamPizza(PizzaIngredientFactory& factory)
    : m_factory(factory)
{
}

std::string ClamPizza::getName() const { return "Clam Pizza"; }

void ClamPizza::prepare()
{
    std::cout << "Preparing " << getName() << "\n";
    std::cout << "  Dough: " << m_factory.createDough() << "\n";
    std::cout << "  Sauce: " << m_factory.createSauce() << "\n";
    std::cout << "  Cheese: " << m_factory.createCheese() << "\n";
    std::cout << "  Clam: " << m_factory.createClam() << "\n";
}

// PepperoniPizza

PepperoniPizza::PepperoniPizza(PizzaIngredientFactory& factory)
    : m_factory(factory)
{
}

std::string PepperoniPizza::getName() const { return "Pepperoni Pizza"; }

void PepperoniPizza::prepare()
{
    std::cout << "Preparing " << getName() << "\n";
    std::cout << "  Dough: " << m_factory.createDough() << "\n";
    std::cout << "  Sauce: " << m_factory.createSauce() << "\n";
    std::cout << "  Cheese: " << m_factory.createCheese() << "\n";
}

// PizzaStore

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
        return std::make_unique<CheesePizza>(m_factory);
    case PizzaType::clam:
        return std::make_unique<ClamPizza>(m_factory);
    case PizzaType::pepperoni:
        return std::make_unique<PepperoniPizza>(m_factory);
    }
    return nullptr;
}

std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(PizzaType type)
{
    switch (type) {
    case PizzaType::cheese:
        return std::make_unique<CheesePizza>(m_factory);
    case PizzaType::clam:
        return std::make_unique<ClamPizza>(m_factory);
    case PizzaType::pepperoni:
        return std::make_unique<PepperoniPizza>(m_factory);
    }
    return nullptr;
}
