#include "observer.hpp"

#include <memory>

int main()
{
    // create subject and observer
    auto weatherData = std::make_shared<WeatherData>();
    BasicDisplay basicDisplay(weatherData);

    // observer notified when weather changes
    weatherData->setTemp(85);
    weatherData->setHumidity(95);
    weatherData->notifyObservers();

    // add a new observer within a scope
    {
        HeatIndexDisplay tempHeatDisplay(weatherData);
        weatherData->setTemp(90);
        weatherData->setHumidity(98);
        weatherData->notifyObservers();
    } // tempHeatDisplay destructor automatically removes it from weatherData

    // now only basicDisplay should receive notifications
    weatherData->setTemp(75);
    weatherData->setHumidity(60);
    weatherData->notifyObservers();

    return 0;
}
