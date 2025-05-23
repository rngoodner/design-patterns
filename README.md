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
    public void setQuack(std::unique_ptr__QuackBehavior qb)

    private std::unique_ptr__QuackBehavior m_quackBehavior
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

class BasicWeatherDataDisplay {
    public BasicWeatherDataDisplay(std::shared_ptr__WeatherData__ weatherData);
    public ~BasicWeatherDataDisplay() override;
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
Observer <|.. BasicWeatherDataDisplay
Observer <|.. HeatIndexDisplay
WeatherData --> Observer
BasicWeatherDataDisplay --> WeatherData
HeatIndexDisplay --> WeatherData
```
