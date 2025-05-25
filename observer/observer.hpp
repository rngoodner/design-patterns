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

// Subject interface
class Subject {
public:
    virtual ~Subject() = default;
    virtual void registerObserver(Observer*) = 0;
    virtual void removeObserver(Observer*) = 0;
    virtual void notifyObservers() = 0;
};

// WeatherData concrete Subject
class WeatherData : public Subject {
public:
    void registerObserver(Observer* observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObservers() override;
    void setTemp(double tempF);
    double getTemp() const;
    void setHumidity(double humidity);
    double getHumidity() const;

private:
    std::vector<Observer*> m_observers;
    double m_tempF;
    double m_humidity;
};

// BasicWeatherDataDisplay concrete Observer
class BasicWeatherDataDisplay : public Observer {
public:
    BasicWeatherDataDisplay(std::shared_ptr<WeatherData> weatherData);
    ~BasicWeatherDataDisplay() override;
    void update() override;

private:
    std::shared_ptr<WeatherData> m_weatherData;
};

// HeatIndexDisplay concrete Observer
class HeatIndexDisplay : public Observer {
public:
    HeatIndexDisplay(std::shared_ptr<WeatherData> weatherData);
    ~HeatIndexDisplay() override;
    void update() override;

private:
    std::shared_ptr<WeatherData> m_weatherData;
    double getHeatIndex(double temp, double humidity);
};

#endif // OBSERVER_HPP
