#include "observer.hpp"

#include <memory>

int main()
{
    // create a WeatherData object
    auto weatherData = std::make_shared<WeatherData>();

    // create a BasicWeatherDataDisplay object
    std::shared_ptr<Observer> basicDisplay = std::make_shared<BasicWeatherDataDisplay>(weatherData);

    // create a HeatIndexDisplay object
    std::shared_ptr<Observer> heatIndexDisplay = std::make_shared<HeatIndexDisplay>(weatherData);

    // update the weather data
    weatherData->setTemp(85);
    weatherData->setHumidity(95);

    // notify observers
    weatherData->notifyObservers();

    return 0;
}
