#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include <memory>
#include <string>

namespace af {

enum class PizzaType {
    cheese,
    pepperoni
};

// pizza ingredient factory interface
class PizzaIngredientFactory {
public:
    virtual ~PizzaIngredientFactory() = default;
    virtual std::string createDough() const = 0;
    virtual std::string createSauce() const = 0;
};

class NyIngredientFactory : public PizzaIngredientFactory {
public:
    std::string createDough() const override;
    std::string createSauce() const override;
};

class ChicagoIngredientFactory : public PizzaIngredientFactory {
public:
    std::string createDough() const override;
    std::string createSauce() const override;
};

// pizza class interface
class Pizza {
public:
    virtual ~Pizza() = default;
    virtual std::string getDescription() const = 0;
};

// notice compared to the factory method pattern we now have only one concrete class for each
// pizza type, but they can still be region specific by passing a different ingredient factory

// concrete cheese pizza
class CheesePizza : public Pizza {
public:
    CheesePizza(PizzaIngredientFactory& factory);
    std::string getDescription() const override;

private:
    PizzaIngredientFactory& m_factory;
};

// concrete pepperoni pizza
class PepperoniPizza : public Pizza {
public:
    PepperoniPizza(PizzaIngredientFactory& factory);
    std::string getDescription() const override;

private:
    PizzaIngredientFactory& m_factory;
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
    NyIngredientFactory m_factory;
};

// concrete chicago pizza store
class ChicagoPizzaStore : public PizzaStore {
private:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override;
    ChicagoIngredientFactory m_factory;
};

} // namespace af

#endif // ABSTRACT_FACTORY_HPP
