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

void SteepedTea::brew()
{
    std::cout << "Steeping the tea\n";
}

void SteepedTea::addCondiments()
{
    std::cout << "Adding lemon\n";
}

// hook: this tea drinker takes it plain
bool SteepedTea::customerWantsCondiments()
{
    return false;
}
