#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <memory>
#include <string>

// Beverage component interface
class Beverage {
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete beverages
class Espresso : public Beverage {
public:
    std::string getDescription() const override;
    double cost() const override;
};

class HouseBlend : public Beverage {
public:
    std::string getDescription() const override;
    double cost() const override;
};

class DarkRoast : public Beverage {
public:
    std::string getDescription() const override;
    double cost() const override;
};

// Condiment decorator base — wraps a Beverage and forces subclasses to implement both methods
class CondimentDecorator : public Beverage {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete decorators
class Milk : public CondimentDecorator {
public:
    explicit Milk(std::shared_ptr<Beverage> beverage);
    std::string getDescription() const override;
    double cost() const override;

private:
    std::shared_ptr<Beverage> m_beverage;
};

class Mocha : public CondimentDecorator {
public:
    explicit Mocha(std::shared_ptr<Beverage> beverage);
    std::string getDescription() const override;
    double cost() const override;

private:
    std::shared_ptr<Beverage> m_beverage;
};

class Soy : public CondimentDecorator {
public:
    explicit Soy(std::shared_ptr<Beverage> beverage);
    std::string getDescription() const override;
    double cost() const override;

private:
    std::shared_ptr<Beverage> m_beverage;
};

class Whip : public CondimentDecorator {
public:
    explicit Whip(std::shared_ptr<Beverage> beverage);
    std::string getDescription() const override;
    double cost() const override;

private:
    std::shared_ptr<Beverage> m_beverage;
};

#endif // DECORATOR_HPP
