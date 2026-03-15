#include "observer.hpp"

#include <algorithm>
#include <iostream>

// WeatherData

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
    for (const auto& observer : m_observers)
        observer->update();
}

void WeatherData::setMeasurements(double tempF, double humidity, double pressure)
{
    m_tempF = tempF;
    m_humidity = humidity;
    m_pressure = pressure;
    notifyObservers();
}

double WeatherData::getTemp() const { return m_tempF; }
double WeatherData::getHumidity() const { return m_humidity; }
double WeatherData::getPressure() const { return m_pressure; }

// CurrentConditionsDisplay

CurrentConditionsDisplay::CurrentConditionsDisplay(std::shared_ptr<WeatherData> weatherData)
    : m_weatherData(weatherData)
{
    m_weatherData->registerObserver(this);
}

CurrentConditionsDisplay::~CurrentConditionsDisplay()
{
    m_weatherData->removeObserver(this);
}

void CurrentConditionsDisplay::update()
{
    m_temp = m_weatherData->getTemp();
    m_humidity = m_weatherData->getHumidity();
    display();
}

void CurrentConditionsDisplay::display() const
{
    std::cout << "Current conditions: " << m_temp << "F degrees and " << m_humidity << "% humidity\n";
}

// StatisticsDisplay

StatisticsDisplay::StatisticsDisplay(std::shared_ptr<WeatherData> weatherData)
    : m_weatherData(weatherData)
{
    m_weatherData->registerObserver(this);
}

StatisticsDisplay::~StatisticsDisplay()
{
    m_weatherData->removeObserver(this);
}

void StatisticsDisplay::update()
{
    double temp = m_weatherData->getTemp();
    if (temp < m_minTemp)
        m_minTemp = temp;
    if (temp > m_maxTemp)
        m_maxTemp = temp;
    m_sumTemp += temp;
    ++m_numReadings;
    display();
}

void StatisticsDisplay::display() const
{
    std::cout << "Avg/Max/Min temperature: " << (m_sumTemp / m_numReadings)
              << "/" << m_maxTemp << "/" << m_minTemp << "\n";
}

// ForecastDisplay

ForecastDisplay::ForecastDisplay(std::shared_ptr<WeatherData> weatherData)
    : m_weatherData(weatherData)
{
    m_weatherData->registerObserver(this);
}

ForecastDisplay::~ForecastDisplay()
{
    m_weatherData->removeObserver(this);
}

void ForecastDisplay::update()
{
    m_lastPressure = m_currentPressure;
    m_currentPressure = m_weatherData->getPressure();
    display();
}

void ForecastDisplay::display() const
{
    if (m_currentPressure > m_lastPressure)
        std::cout << "Forecast: improving weather on the way!\n";
    else if (m_currentPressure == m_lastPressure)
        std::cout << "Forecast: more of the same\n";
    else
        std::cout << "Forecast: watch out for cooler, rainy weather\n";
}
