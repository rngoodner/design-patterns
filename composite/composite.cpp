#include "composite.hpp"

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>

// MenuComponent defaults — leaf classes (MenuItem) override getPrice() and isVegetarian()

void MenuComponent::add(std::unique_ptr<MenuComponent> /*component*/)
{
    // leaf nodes do not support add
}

double MenuComponent::getPrice() const
{
    throw std::runtime_error("getPrice not supported");
}

bool MenuComponent::isVegetarian() const
{
    throw std::runtime_error("isVegetarian not supported");
}

// MenuItem

MenuItem::MenuItem(std::string name, std::string description, bool vegetarian, double price)
    : m_name(std::move(name))
    , m_description(std::move(description))
    , m_vegetarian(vegetarian)
    , m_price(price)
{
}

std::string MenuItem::getName() const { return m_name; }
std::string MenuItem::getDescription() const { return m_description; }
double MenuItem::getPrice() const { return m_price; }
bool MenuItem::isVegetarian() const { return m_vegetarian; }

void MenuItem::print() const
{
    std::cout << "  " << m_name
              << (m_vegetarian ? " (v)" : "")
              << " $" << std::fixed << std::setprecision(2) << m_price
              << "\n     " << m_description << "\n";
}

// Menu

Menu::Menu(std::string name, std::string description)
    : m_name(std::move(name))
    , m_description(std::move(description))
{
}

void Menu::add(std::unique_ptr<MenuComponent> component)
{
    m_children.push_back(std::move(component));
}

std::string Menu::getName() const { return m_name; }
std::string Menu::getDescription() const { return m_description; }

void Menu::print() const
{
    std::cout << "\n"
              << m_name << ": " << m_description << "\n";
    std::cout << "---\n";
    for (const auto& child : m_children)
        child->print();
}
