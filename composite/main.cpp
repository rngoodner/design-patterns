#include "composite.hpp"

#include <memory>

int main()
{
    auto allMenus = std::make_unique<Menu>("All Menus", "All menus combined");

    auto breakfastMenu = std::make_unique<Menu>("Pancake House Menu", "Breakfast");
    breakfastMenu->add(std::make_unique<MenuItem>("K&B Pancake Breakfast", "Pancakes with eggs", true, 2.99));
    breakfastMenu->add(std::make_unique<MenuItem>("Regular Pancake Breakfast", "Pancakes with sausage", false, 2.99));
    breakfastMenu->add(std::make_unique<MenuItem>("Blueberry Pancakes", "Pancakes with blueberries", true, 3.49));

    auto dinerMenu = std::make_unique<Menu>("Diner Menu", "Lunch");
    dinerMenu->add(std::make_unique<MenuItem>("Vegetarian BLT", "Fakin' bacon with lettuce and tomato", true, 2.99));
    dinerMenu->add(std::make_unique<MenuItem>("BLT", "Bacon with lettuce and tomato", false, 2.99));
    dinerMenu->add(std::make_unique<MenuItem>("Soup of the day", "Soup with a side salad", false, 3.29));

    // dessert sub-menu nested inside the diner menu — menus and items treated uniformly
    auto dessertMenu = std::make_unique<Menu>("Dessert Menu", "Dessert");
    dessertMenu->add(std::make_unique<MenuItem>("Apple Pie", "Apple pie with a flaky crust", true, 1.59));
    dinerMenu->add(std::move(dessertMenu));

    allMenus->add(std::move(breakfastMenu));
    allMenus->add(std::move(dinerMenu));
    allMenus->print();
}
