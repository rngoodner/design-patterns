#include "template-method.hpp"

int main()
{
    FilterCoffee coffee;
    SteepedTea tea;

    // both follow the same algorithm skeleton; only brew() and addCondiments() differ
    coffee.prepareRecipe();
    tea.prepareRecipe();
}
