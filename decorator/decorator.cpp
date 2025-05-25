#include "decorator.hpp"

std::string Coffee::getDescription() const
{
    return "Coffee";
}

std::string Tea::getDescription() const
{
    return "Tea";
}

Milk::Milk(std::shared_ptr<Beverage> beverage)
    : m_beverage(beverage)
{
}

std::string Milk::getDescription() const
{
    return m_beverage->getDescription() + " + Milk";
}

Soy::Soy(std::shared_ptr<Beverage> beverage)
    : m_beverage(beverage)
{
}

std::string Soy::getDescription() const
{
    return m_beverage->getDescription() + " + Soy";
}

Whip::Whip(std::shared_ptr<Beverage> beverage)
    : m_beverage(beverage)
{
}

std::string Whip::getDescription() const
{
    return m_beverage->getDescription() + " + Whip";
}

Sugar::Sugar(std::shared_ptr<Beverage> beverage)
    : m_beverage(beverage)
{
}

std::string Sugar::getDescription() const
{
    return m_beverage->getDescription() + " + Sugar";
}
