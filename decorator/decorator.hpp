#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <memory>
#include <string>

// Beverage component interface
class Beverage {
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const = 0;
};

// Coffee concrete beverage
class Coffee : public Beverage {
public:
    std::string getDescription() const override;
};

// Tea concrete beverage
class Tea : public Beverage {
public:
    std::string getDescription() const override;
};

// Beverage decorator interface
class BeverageDecorator : public Beverage { };

// Milk concrete decorator
class Milk : public BeverageDecorator {
public:
    Milk(std::shared_ptr<Beverage> beverage);
    std::string getDescription() const override;

private:
    std::shared_ptr<Beverage> m_beverage;
};

// Soy concrete decorator
class Soy : public BeverageDecorator {
public:
    Soy(std::shared_ptr<Beverage> beverage);
    std::string getDescription() const override;

private:
    std::shared_ptr<Beverage> m_beverage;
};

// Whip concrete decorator
class Whip : public BeverageDecorator {
public:
    Whip(std::shared_ptr<Beverage> beverage);
    std::string getDescription() const override;

private:
    std::shared_ptr<Beverage> m_beverage;
};

// Sugar concrete decorator
class Sugar : public BeverageDecorator {
public:
    Sugar(std::shared_ptr<Beverage> beverage);
    std::string getDescription() const override;

private:
    std::shared_ptr<Beverage> m_beverage;
};

#endif // DECORATOR_HPP
