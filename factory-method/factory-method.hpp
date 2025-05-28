#ifndef FACTORY_METHOD_HPP
#define FACTORY_METHOD_HPP

#include <memory>
#include <string>

enum class PizzaType {
    cheese,
    pepperoni
};

// pizza class interface
class Pizza {
public:
    virtual ~Pizza() = default;
    virtual std::string getDescription() const = 0;
};

// concrete ny cheese pizza
class NyCheesePizza : public Pizza {
public:
    std::string getDescription() const override;
};

// concrete ny pepperoni pizza
class NyPepperoniPizza : public Pizza {
public:
    std::string getDescription() const override;
};

// concrete chicago cheese pizza
class ChicagoCheesePizza : public Pizza {
public:
    std::string getDescription() const override;
};

// concrete chicago pepperoni pizza
class ChicagoPepperoniPizza : public Pizza {
public:
    std::string getDescription() const override;
};

// pizza store interface
// notice orderPizza() works the same for all PizzaStores and we add new behavior by
// creating new stores that implement the createPizza() factory method instead of having
// to continue changing PizzaStore itself.
class PizzaStore {
public:
    virtual ~PizzaStore() = default;
    std::unique_ptr<Pizza> orderPizza(PizzaType type);

private:
    virtual std::unique_ptr<Pizza> createPizza(PizzaType type) = 0;
};

// concrete ny pizza store
class NyPizzaStore : public PizzaStore {
private:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override;
};

// concrete chicago pizza store
class ChicagoPizzaStore : public PizzaStore {
private:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override;
};

#endif // FACTORY_METHOD_HPP
