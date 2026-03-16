#include "template-method.hpp"

#include <iostream>

int main()
{
    FilterCoffee coffee;
    SteepedTea teaWithLemon { true }; // customer wants lemon
    SteepedTea teaPlain { false }; // customer declines lemon

    // coffee uses the default hook (always adds condiments)
    coffee.prepareRecipe();
    std::cout << "\n";
    // tea overrides the hook — same class, same algorithm, condiments driven by customer preference
    teaWithLemon.prepareRecipe();
    std::cout << "\n";
    teaPlain.prepareRecipe();
}
