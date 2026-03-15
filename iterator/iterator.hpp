#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <memory>
#include <string>
#include <vector>

// menu item value type
struct MenuEntry {
    std::string name;
    std::string description;
    bool vegetarian;
    double price;
};

// iterator interface
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;
    virtual MenuEntry next() = 0;
};

// diner menu backed by a fixed-size array
class DinerMenu {
public:
    static constexpr int c_maxItems = 6;
    DinerMenu();
    std::unique_ptr<Iterator> createIterator() const;

private:
    MenuEntry m_items[c_maxItems];
    int m_count { 0 };
    void addItem(std::string name, std::string description, bool vegetarian, double price);
};

// iterator over DinerMenu's fixed array
class DinerMenuIterator : public Iterator {
public:
    DinerMenuIterator(const MenuEntry* items, int count);
    bool hasNext() const override;
    MenuEntry next() override;

private:
    const MenuEntry* m_items;
    int m_count;
    int m_position { 0 };
};

// pancake house menu backed by a vector
class PancakeHouseMenu {
public:
    PancakeHouseMenu();
    std::unique_ptr<Iterator> createIterator() const;

private:
    std::vector<MenuEntry> m_items;
    void addItem(std::string name, std::string description, bool vegetarian, double price);
};

// iterator over PancakeHouseMenu's vector
class PancakeMenuIterator : public Iterator {
public:
    explicit PancakeMenuIterator(const std::vector<MenuEntry>& items);
    bool hasNext() const override;
    MenuEntry next() override;

private:
    const std::vector<MenuEntry>& m_items;
    int m_position { 0 };
};

#endif // ITERATOR_HPP
