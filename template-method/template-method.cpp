#include "template-method.hpp"

#include <iostream>

void CaffeineBeverage::prepareRecipe()
{
    boilWater();
    brew();
    pourInCup();
    if (customerWantsCondiments())
        addCondiments();
}

void CaffeineBeverage::boilWater()
{
    std::cout << "Boiling water\n";
}

void CaffeineBeverage::pourInCup()
{
    std::cout << "Pouring into cup\n";
}

bool CaffeineBeverage::customerWantsCondiments()
{
    return true;
}

void FilterCoffee::brew()
{
    std::cout << "Dripping coffee through filter\n";
}

void FilterCoffee::addCondiments()
{
    std::cout << "Adding sugar and milk\n";
}

SteepedTea::SteepedTea(bool wantsCondiments)
    : m_wantsCondiments(wantsCondiments)
{
}

void SteepedTea::brew()
{
    std::cout << "Steeping the tea\n";
}

void SteepedTea::addCondiments()
{
    std::cout << "Adding lemon\n";
}

bool SteepedTea::customerWantsCondiments()
{
    return m_wantsCondiments;
}
