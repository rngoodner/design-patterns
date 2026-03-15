#include "iterator.hpp"

#include <iomanip>
#include <iostream>

void printMenu(Iterator& iterator)
{
    while (iterator.hasNext()) {
        auto item = iterator.next();
        std::cout << item.name
                  << " $" << std::fixed << std::setprecision(2) << item.price
                  << (item.vegetarian ? " (v)" : "")
                  << "\n"
                  << "   " << item.description << "\n";
    }
}

int main()
{
    PancakeHouseMenu pancakeMenu;
    DinerMenu dinerMenu;

    // both menus expose items through the same Iterator interface
    auto pancakeIterator = pancakeMenu.createIterator();
    auto dinerIterator = dinerMenu.createIterator();

    std::cout << "--- Pancake House Menu ---\n";
    printMenu(*pancakeIterator);

    std::cout << "--- Diner Menu ---\n";
    printMenu(*dinerIterator);
}
