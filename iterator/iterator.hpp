#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <array>
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
    static constexpr size_t c_maxItems = 6;
    DinerMenu();
    std::unique_ptr<Iterator> createIterator() const;

private:
    std::array<MenuEntry, c_maxItems> m_items {};
    size_t m_count { 0 };
    void addItem(std::string name, std::string description, bool vegetarian, double price);
};

// iterator over DinerMenu's fixed array
class DinerMenuIterator : public Iterator {
public:
    DinerMenuIterator(const std::array<MenuEntry, DinerMenu::c_maxItems>& items, size_t count);
    bool hasNext() const override;
    MenuEntry next() override;

private:
    const std::array<MenuEntry, DinerMenu::c_maxItems>& m_items;
    size_t m_count;
    size_t m_position { 0 };
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
    size_t m_position { 0 };
};

#endif // ITERATOR_HPP
