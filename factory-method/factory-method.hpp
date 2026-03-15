#ifndef FACTORY_METHOD_HPP
#define FACTORY_METHOD_HPP

#include <memory>
#include <string>

enum class PizzaType {
    cheese,
    veggie,
    clam,
    pepperoni
};

// Pizza abstract class — defines the lifecycle; concrete classes provide name and can override steps
class Pizza {
public:
    virtual ~Pizza() = default;
    virtual std::string getName() const = 0;
    void prepare();
    void bake();
    void cut();
    void box();

protected:
    // Chicago-style pizzas override cut() to cut in squares
    virtual void doCut();
};

class NyCheesePizza : public Pizza {
public:
    std::string getName() const override;
};

class NyVeggiePizza : public Pizza {
public:
    std::string getName() const override;
};

class NyClamPizza : public Pizza {
public:
    std::string getName() const override;
};

class NyPepperoniPizza : public Pizza {
public:
    std::string getName() const override;
};

class ChicagoCheesePizza : public Pizza {
public:
    std::string getName() const override;

protected:
    void doCut() override;
};

class ChicagoVeggiePizza : public Pizza {
public:
    std::string getName() const override;

protected:
    void doCut() override;
};

class ChicagoClamPizza : public Pizza {
public:
    std::string getName() const override;

protected:
    void doCut() override;
};

class ChicagoPepperoniPizza : public Pizza {
public:
    std::string getName() const override;

protected:
    void doCut() override;
};

// PizzaStore defines the ordering process; createPizza() is the factory method
class PizzaStore {
public:
    virtual ~PizzaStore() = default;
    // orderPizza() is the invariant — it controls the pizza lifecycle
    std::unique_ptr<Pizza> orderPizza(PizzaType type);

private:
    // factory method: subclasses decide which concrete Pizza to create
    virtual std::unique_ptr<Pizza> createPizza(PizzaType type) = 0;
};

class NyPizzaStore : public PizzaStore {
private:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override;
};

class ChicagoPizzaStore : public PizzaStore {
private:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override;
};

#endif // FACTORY_METHOD_HPP
