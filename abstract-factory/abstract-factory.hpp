#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include <memory>
#include <string>

namespace af {

enum class PizzaType {
    cheese,
    clam,
    pepperoni
};

// Abstract factory: creates a family of related ingredients
class PizzaIngredientFactory {
public:
    virtual ~PizzaIngredientFactory() = default;
    virtual std::string createDough() const = 0;
    virtual std::string createSauce() const = 0;
    virtual std::string createCheese() const = 0;
    virtual std::string createClam() const = 0;
};

class NyIngredientFactory : public PizzaIngredientFactory {
public:
    std::string createDough() const override;
    std::string createSauce() const override;
    std::string createCheese() const override;
    std::string createClam() const override;
};

class ChicagoIngredientFactory : public PizzaIngredientFactory {
public:
    std::string createDough() const override;
    std::string createSauce() const override;
    std::string createCheese() const override;
    std::string createClam() const override;
};

// Pizza abstract class — prepare() uses the ingredient factory; lifecycle same as factory-method
class Pizza {
public:
    virtual ~Pizza() = default;
    virtual std::string getName() const = 0;
    virtual void prepare() = 0;
    void bake();
    void cut();
    void box();
};

// One concrete pizza class per type; ingredients come from whichever factory is passed in
// (compare to factory-method, which needed a separate class per region × type)

class CheesePizza : public Pizza {
public:
    CheesePizza(PizzaIngredientFactory& factory);
    std::string getName() const override;
    void prepare() override;

private:
    PizzaIngredientFactory& m_factory;
};

class ClamPizza : public Pizza {
public:
    ClamPizza(PizzaIngredientFactory& factory);
    std::string getName() const override;
    void prepare() override;

private:
    PizzaIngredientFactory& m_factory;
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza(PizzaIngredientFactory& factory);
    std::string getName() const override;
    void prepare() override;

private:
    PizzaIngredientFactory& m_factory;
};

// PizzaStore uses a factory method (createPizza) and an ingredient factory
class PizzaStore {
public:
    virtual ~PizzaStore() = default;
    std::unique_ptr<Pizza> orderPizza(PizzaType type);

private:
    virtual std::unique_ptr<Pizza> createPizza(PizzaType type) = 0;
};

class NyPizzaStore : public PizzaStore {
private:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override;
    NyIngredientFactory m_factory;
};

class ChicagoPizzaStore : public PizzaStore {
private:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override;
    ChicagoIngredientFactory m_factory;
};

} // namespace af

#endif // ABSTRACT_FACTORY_HPP
