#include "observer.hpp"

#include <iostream>

void WeatherData::registerObserver(Observer* observer)
{
    m_observers.push_back(observer);
}

void WeatherData::removeObserver(Observer* observer)
{
    m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
}

void WeatherData::notifyObservers()
{
    for (const auto& observer : m_observers) {
        observer->update();
    }
}

void WeatherData::setTemp(double tempF)
{
    m_tempF = tempF;
    // could also notify here
}

double WeatherData::getTemp() const
{
    return m_tempF;
    // could also notify here
}

void WeatherData::setHumidity(double humidity)
{
    m_humidity = humidity;
}

double WeatherData::getHumidity() const
{
    return m_humidity;
}

BasicDisplay::BasicDisplay(std::shared_ptr<WeatherData> weatherData)
    : m_weatherData(weatherData)
{
    m_weatherData->registerObserver(this);
}

BasicDisplay::~BasicDisplay()
{
    m_weatherData->removeObserver(this);
}

void BasicDisplay::update()
{
    std::cout << "\nBasic Display Observed an update:\n";
    std::cout << "Temperature: " << m_weatherData->getTemp() << "F\n";
    std::cout << "Humidity: " << m_weatherData->getHumidity() << "%\n";
}

HeatIndexDisplay::HeatIndexDisplay(std::shared_ptr<WeatherData> weatherData)
    : m_weatherData(weatherData)
{
    m_weatherData->registerObserver(this);
}

HeatIndexDisplay::~HeatIndexDisplay()
{
    m_weatherData->removeObserver(this);
}

void HeatIndexDisplay::update()
{
    std::cout << "\nHeat Index Display Observed an update:\n";
    std::cout << "Heat Index: " << getHeatIndex(m_weatherData->getTemp(), m_weatherData->getHumidity()) << "F\n";
}

double HeatIndexDisplay::getHeatIndex(double temp, double humidity)
{
    // Official NWS Rothfusz regression equation for heat index
    return -42.379 + 2.04901523 * temp + 10.14333127 * humidity - 0.22475541 * temp * humidity
        - 0.00683783 * temp * temp - 0.05481717 * humidity * humidity + 0.00122874 * temp * temp * humidity
        + 0.00085282 * temp * humidity * humidity - 0.00000199 * temp * temp * humidity * humidity;
}
