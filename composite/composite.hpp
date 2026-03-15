#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <memory>
#include <string>
#include <vector>

// component base class for both menu items and menus
class MenuComponent {
public:
    virtual ~MenuComponent() = default;
    virtual void add(std::unique_ptr<MenuComponent> component);
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
    virtual double getPrice() const;
    virtual bool isVegetarian() const;
    virtual void print() const = 0;
};

// leaf: a single menu item
class MenuItem : public MenuComponent {
public:
    MenuItem(std::string name, std::string description, bool vegetarian, double price);
    std::string getName() const override;
    std::string getDescription() const override;
    double getPrice() const override;
    bool isVegetarian() const override;
    void print() const override;

private:
    std::string m_name;
    std::string m_description;
    bool m_vegetarian;
    double m_price;
};

// composite: a menu that can hold menu items or other menus
class Menu : public MenuComponent {
public:
    Menu(std::string name, std::string description);
    void add(std::unique_ptr<MenuComponent> component) override;
    std::string getName() const override;
    std::string getDescription() const override;
    void print() const override;

private:
    std::string m_name;
    std::string m_description;
    std::vector<std::unique_ptr<MenuComponent>> m_children;
};

#endif // COMPOSITE_HPP
