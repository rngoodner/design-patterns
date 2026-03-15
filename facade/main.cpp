#include "facade.hpp"

int main()
{
    Amplifier amp;
    DvdPlayer dvd;
    Projector projector;
    Screen screen;
    TheaterLights lights;
    PopcornPopper popper;

    // one call hides the complexity of coordinating all subsystem components
    HomeTheaterFacade homeTheater { amp, dvd, projector, screen, lights, popper };
    homeTheater.watchMovie("Raiders of the Lost Ark");
    homeTheater.endMovie();
}
