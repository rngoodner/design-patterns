#include "iterator.hpp"

#include <utility>

DinerMenu::DinerMenu()
{
    addItem("Vegetarian BLT", "Fakin' bacon with lettuce and tomato on whole wheat", true, 2.99);
    addItem("BLT", "Bacon with lettuce and tomato on whole wheat", false, 2.99);
    addItem("Soup of the day", "Soup with a side salad", false, 3.29);
    addItem("Hotdog", "A hotdog with sauerkraut", false, 3.05);
}

void DinerMenu::addItem(std::string name, std::string description, bool vegetarian, double price)
{
    if (m_count < c_maxItems)
        m_items[m_count++] = { std::move(name), std::move(description), vegetarian, price };
}

std::unique_ptr<Iterator> DinerMenu::createIterator() const
{
    return std::make_unique<DinerMenuIterator>(m_items, m_count);
}

DinerMenuIterator::DinerMenuIterator(const std::array<MenuEntry, DinerMenu::c_maxItems>& items, size_t count)
    : m_items(items)
    , m_count(count)
{
}

bool DinerMenuIterator::hasNext() const
{
    return m_position < m_count;
}

MenuEntry DinerMenuIterator::next()
{
    return m_items[m_position++];
}

PancakeHouseMenu::PancakeHouseMenu()
{
    addItem("K&B Pancake Breakfast", "Pancakes with scrambled eggs and toast", true, 2.99);
    addItem("Regular Pancake Breakfast", "Pancakes with fried eggs and sausage", false, 2.99);
    addItem("Blueberry Pancakes", "Pancakes made with fresh blueberries", true, 3.49);
}

void PancakeHouseMenu::addItem(std::string name, std::string description, bool vegetarian, double price)
{
    m_items.push_back({ std::move(name), std::move(description), vegetarian, price });
}

std::unique_ptr<Iterator> PancakeHouseMenu::createIterator() const
{
    return std::make_unique<PancakeMenuIterator>(m_items);
}

PancakeMenuIterator::PancakeMenuIterator(const std::vector<MenuEntry>& items)
    : m_items(items)
{
}

bool PancakeMenuIterator::hasNext() const
{
    return m_position < m_items.size();
}

MenuEntry PancakeMenuIterator::next()
{
    return m_items[m_position++];
}
