#include "decorator.hpp"

std::string Espresso::getDescription() const
{
    return "Espresso";
}

double Espresso::cost() const
{
    return 1.99;
}

std::string HouseBlend::getDescription() const
{
    return "House Blend Coffee";
}

double HouseBlend::cost() const
{
    return 0.89;
}

std::string DarkRoast::getDescription() const
{
    return "Dark Roast Coffee";
}

double DarkRoast::cost() const
{
    return 0.99;
}

Milk::Milk(std::shared_ptr<Beverage> beverage)
    : m_beverage(beverage)
{
}

std::string Milk::getDescription() const
{
    return m_beverage->getDescription() + ", Milk";
}

double Milk::cost() const
{
    return m_beverage->cost() + 0.25;
}

Mocha::Mocha(std::shared_ptr<Beverage> beverage)
    : m_beverage(beverage)
{
}

std::string Mocha::getDescription() const
{
    return m_beverage->getDescription() + ", Mocha";
}

double Mocha::cost() const
{
    return m_beverage->cost() + 0.20;
}

Soy::Soy(std::shared_ptr<Beverage> beverage)
    : m_beverage(beverage)
{
}

std::string Soy::getDescription() const
{
    return m_beverage->getDescription() + ", Soy";
}

double Soy::cost() const
{
    return m_beverage->cost() + 0.15;
}

Whip::Whip(std::shared_ptr<Beverage> beverage)
    : m_beverage(beverage)
{
}

std::string Whip::getDescription() const
{
    return m_beverage->getDescription() + ", Whip";
}

double Whip::cost() const
{
    return m_beverage->cost() + 0.10;
}
