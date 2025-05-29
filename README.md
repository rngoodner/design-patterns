# design-patterns

C++ examples for the book _Head First Design Patterns 2e._ Simplified to minimal examples and adapted to C++ conventions.

## Strategy Pattern

The Strategy Pattern defines a family of algorithms,
encapsulates each one, and makes them interchangeable.
Strategy lets the algorithm vary independently from
clients that use it.

```mermaid
classDiagram

class QuackBehavior {
    public virtual ~QuackBehavior() = default;
    public virtual void quack() const = 0;
}

class Quack {
    public void quack() const override
}

class Squeak {
    public void quack() const override
}

class Duck {
    public virtual ~Duck() = default
    public virtual void display() const = 0

    public void performQuack()
    public void setQuack(std::unique_ptr__QuackBehavior__ qb)

    private std::unique_ptr__QuackBehavior__ m_quackBehavior
}

class MallardDuck {
    public MallardDuck()
    public void display() const override
}

class RubberDuck {
    public RubberDuck()
    public void display() const override
}

Duck <|.. RubberDuck
Duck <|.. MallardDuck
Duck --> QuackBehavior
QuackBehavior <|.. Quack
QuackBehavior <|.. Squeak
```

## Observer Pattern

The Observer Pattern defines a one-to-many dependency between objects so that when one object changes state, all of its dependents are notified and updated automatically.

```mermaid
classDiagram

class Observer {
    public virtual ~Observer() = default;
    public virtual void update() = 0;
}

class Subject {
    public virtual ~Subject() = default;
    public virtual void registerObserver(Observer*) = 0;
    public virtual void removeObserver(Observer*) = 0;
    public virtual void notifyObservers() = 0;
}

class WeatherData {
    public void registerObserver(Observer* observer) override;
    public void removeObserver(Observer* observer) override;
    public void notifyObservers() override;
    public void setTemp(double tempF);
    public double getTemp() const;
    public void setHumidity(double humidity);
    public double getHumidity() const;

    private std::vector__Observer*__ m_observers;
    private double m_tempF;
    private double m_humidity;
}

class BasicDisplay {
    public BasicDisplay(std::shared_ptr__WeatherData__ weatherData);
    public ~BasicDisplay() override;
    public void update() override;

    private std::shared_ptr__WeatherData__ m_weatherData;
}

class HeatIndexDisplay {
    public HeatIndexDisplay(std::shared_ptr__WeatherData__ weatherData);
    public ~HeatIndexDisplay() override;
    public void update() override;

    private std::shared_ptr__WeatherData__ m_weatherData;
    private double getHeatIndex(double temp, double humidity);
}

Subject <|.. WeatherData
Observer <|.. BasicDisplay
Observer <|.. HeatIndexDisplay
WeatherData --> Observer
BasicDisplay --> WeatherData
HeatIndexDisplay --> WeatherData
```
## Decorator Pattern

The Decorator Pattern attaches additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

```mermaid
classDiagram

class Beverage {
    public virtual ~Beverage() = default;
    public virtual std::string getDescription() const = 0;
}

class Coffee {
    public std::string getDescription() const override;
}

class Tea {
    public std::string getDescription() const override;
}

class Milk {
    public Milk(std::shared_ptr__Beverage__ beverage);
    public std::string getDescription() const override;
    private std::shared_ptr__Beverage__ m_beverage;
}

class Soy {
    public Soy(std::shared_ptr__Beverage__ beverage);
    public std::string getDescription() const override;
    private std::shared_ptr__Beverage__ m_beverage;
}

class Whip {
    public Whip(std::shared_ptr__Beverage__ beverage);
    public std::string getDescription() const override;
    private std::shared_ptr__Beverage__ m_beverage;
}

class Sugar {
    public Sugar(std::shared_ptr__Beverage__ beverage);
    public std::string getDescription() const override;
    private std::shared_ptr__Beverage__ m_beverage;
}

Beverage <|.. Coffee
Beverage <|.. Tea
Beverage <|.. BeverageDecorator
BeverageDecorator <|.. Milk
BeverageDecorator <|.. Soy
BeverageDecorator <|.. Whip
BeverageDecorator <|.. Sugar
Milk --> Beverage
Soy --> Beverage
Whip --> Beverage
Sugar --> Beverage
```

## Factory Method Pattern

The Factory Method Pattern defines an interface for creating an object, but lets subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.

```mermaid
classDiagram

class Pizza {
    public virtual ~Pizza() = default;
    public virtual std::string getDescription() const = 0;
}

class NyCheesePizza {
    public std::string getDescription() const override;
}

class NyPepperoniPizza {
    public std::string getDescription() const override;
}

class ChicagoCheesePizza {
    public std::string getDescription() const override;
}

class ChicagoPepperoniPizza {
    public std::string getDescription() const override;
}

class PizzaStore {
    public virtual ~PizzaStore() = default;
    public std::unique_ptr__Pizza__ orderPizza(PizzaType type);
    private virtual std::unique_ptr__Pizza__ createPizza(PizzaType type) = 0;
}

class NyPizzaStore {
    private std::unique_ptr__Pizza__ createPizza(PizzaType type) override;
}

class ChicagoPizzaStore {
    private std::unique_ptr__Pizza__ createPizza(PizzaType type) override;
}

Pizza <|.. NyCheesePizza
Pizza <|.. NyPepperoniPizza
Pizza <|.. ChicagoCheesePizza
Pizza <|.. ChicagoPepperoniPizza
PizzaStore <|.. NyPizzaStore
PizzaStore <|.. ChicagoPizzaStore
NyPizzaStore --> NyCheesePizza
NyPizzaStore --> NyPepperoniPizza
ChicagoPizzaStore --> ChicagoCheesePizza
ChicagoPizzaStore --> ChicagoPepperoniPizza
```

## Abstract Factory Pattern

The Abstract Factory Pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes.

```mermaid
classDiagram

class PizzaIngredientFactory {
    public virtual ~PizzaIngredientFactory() = default;
    public virtual std::string createDough() const = 0;
    public virtual std::string createSauce() const = 0;
}

class NyIngredientFactory {
    public std::string createDough() const override;
    public std::string createSauce() const override;
}

class ChicagoIngredientFactory {
    public std::string createDough() const override;
    public std::string createSauce() const override;
}

class Pizza {
    public virtual ~Pizza() = default;
    public virtual std::string getDescription() const = 0;
}

class CheesePizza {
    public CheesePizza(PizzaIngredientFactory& factory);
    public std::string getDescription() const override;
    private PizzaIngredientFactory& m_factory;
}

class PepperoniPizza {
    public PepperoniPizza(PizzaIngredientFactory& factory);
    public std::string getDescription() const override;
    private PizzaIngredientFactory& m_factory;
}

class PizzaStore {
    public virtual ~PizzaStore() = default;
    public std::unique_ptr__Pizza__ orderPizza(PizzaType type);
    private virtual std::unique_ptr__Pizza__ createPizza(PizzaType type) = 0;
}

class NyPizzaStore {
    private std::unique_ptr__Pizza__ createPizza(PizzaType type) override;
    private NyIngredientFactory m_factory;
}

class ChicagoPizzaStore {
    private std::unique_ptr__Pizza__ createPizza(PizzaType type) override;
    private ChicagoIngredientFactory m_factory;
}

PizzaIngredientFactory <|.. NyIngredientFactory
PizzaIngredientFactory <|.. ChicagoIngredientFactory
Pizza <|.. CheesePizza
Pizza <|.. PepperoniPizza
PizzaStore <|.. NyPizzaStore
PizzaStore <|.. ChicagoPizzaStore
CheesePizza --> PizzaIngredientFactory
PepperoniPizza --> PizzaIngredientFactory
NyPizzaStore --> NyIngredientFactory
ChicagoPizzaStore --> ChicagoIngredientFactory
NyPizzaStore --> CheesePizza
NyPizzaStore --> PepperoniPizza
ChicagoPizzaStore --> CheesePizza
ChicagoPizzaStore --> PepperoniPizza
```
