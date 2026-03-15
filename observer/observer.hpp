#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <memory>
#include <vector>

// Observer interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

// DisplayElement interface — all displays must implement display()
class DisplayElement {
public:
    virtual ~DisplayElement() = default;
    virtual void display() const = 0;
};

// Subject interface
class Subject {
public:
    virtual ~Subject() = default;
    virtual void registerObserver(Observer*) = 0;
    virtual void removeObserver(Observer*) = 0;
    virtual void notifyObservers() = 0;
};

// WeatherData concrete Subject — holds temperature, humidity, and pressure
class WeatherData : public Subject {
public:
    void registerObserver(Observer* observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObservers() override;
    void setMeasurements(double tempF, double humidity, double pressure);
    double getTemp() const;
    double getHumidity() const;
    double getPressure() const;

private:
    std::vector<Observer*> m_observers;
    double m_tempF { 0 };
    double m_humidity { 0 };
    double m_pressure { 0 };
};

// CurrentConditionsDisplay — shows current temp and humidity
class CurrentConditionsDisplay : public Observer, public DisplayElement {
public:
    explicit CurrentConditionsDisplay(std::shared_ptr<WeatherData> weatherData);
    ~CurrentConditionsDisplay() override;
    void update() override;
    void display() const override;

private:
    std::shared_ptr<WeatherData> m_weatherData;
    double m_temp { 0 };
    double m_humidity { 0 };
};

// StatisticsDisplay — tracks min, max, and average temperature
class StatisticsDisplay : public Observer, public DisplayElement {
public:
    explicit StatisticsDisplay(std::shared_ptr<WeatherData> weatherData);
    ~StatisticsDisplay() override;
    void update() override;
    void display() const override;

private:
    std::shared_ptr<WeatherData> m_weatherData;
    double m_minTemp { 1e9 };
    double m_maxTemp { -1e9 };
    double m_sumTemp { 0 };
    int m_numReadings { 0 };
};

// ForecastDisplay — predicts weather based on barometric pressure trend
class ForecastDisplay : public Observer, public DisplayElement {
public:
    explicit ForecastDisplay(std::shared_ptr<WeatherData> weatherData);
    ~ForecastDisplay() override;
    void update() override;
    void display() const override;

private:
    std::shared_ptr<WeatherData> m_weatherData;
    double m_currentPressure { 29.92 };
    double m_lastPressure { 0 };
};

#endif // OBSERVER_HPP
