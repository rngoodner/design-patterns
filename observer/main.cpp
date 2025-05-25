#include "observer.hpp"

#include <memory>

int main()
{
    // create subject and observers
    auto weatherData = std::make_shared<WeatherData>();
    BasicDisplay basicDisplay(weatherData);
    HeatIndexDisplay heatIndexDisplay(weatherData);

    // update the subject and notify obervers
    weatherData->setTemp(85);
    weatherData->setHumidity(95);
    weatherData->notifyObservers();

    // remove an observer, update subject, and notify observers again
    heatIndexDisplay.~HeatIndexDisplay();
    weatherData->setTemp(90);
    weatherData->setHumidity(98);
    weatherData->notifyObservers();

    return 0;
}
