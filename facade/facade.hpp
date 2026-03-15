#ifndef FACADE_HPP
#define FACADE_HPP

#include <string>

// subsystem classes
class Amplifier {
public:
    void on();
    void off();
    void setVolume(int level);
    void setSurroundSound();
};

class DvdPlayer {
public:
    void on();
    void off();
    void play(const std::string& movie);
    void stop();
};

class Projector {
public:
    void on();
    void off();
    void wideScreenMode();
};

class Screen {
public:
    void down();
    void up();
};

class TheaterLights {
public:
    void on();
    void dim(int level);
};

class PopcornPopper {
public:
    void on();
    void off();
    void pop();
};

// facade providing a simplified interface to the home theater subsystem
class HomeTheaterFacade {
public:
    HomeTheaterFacade(Amplifier& amp, DvdPlayer& dvd, Projector& projector,
        Screen& screen, TheaterLights& lights, PopcornPopper& popper);
    void watchMovie(const std::string& movie);
    void endMovie();

private:
    Amplifier& m_amp;
    DvdPlayer& m_dvd;
    Projector& m_projector;
    Screen& m_screen;
    TheaterLights& m_lights;
    PopcornPopper& m_popper;
};

#endif // FACADE_HPP
