#include "facade.hpp"

#include <iostream>

void Amplifier::on() { std::cout << "Amplifier on\n"; }
void Amplifier::off() { std::cout << "Amplifier off\n"; }
void Amplifier::setVolume(int level) { std::cout << "Amplifier volume set to " << level << "\n"; }
void Amplifier::setSurroundSound() { std::cout << "Amplifier surround sound on\n"; }

void DvdPlayer::on() { std::cout << "DVD Player on\n"; }
void DvdPlayer::off() { std::cout << "DVD Player off\n"; }
void DvdPlayer::play(const std::string& movie) { std::cout << "DVD Player playing \"" << movie << "\"\n"; }
void DvdPlayer::stop() { std::cout << "DVD Player stopped\n"; }

void Projector::on() { std::cout << "Projector on\n"; }
void Projector::off() { std::cout << "Projector off\n"; }
void Projector::wideScreenMode() { std::cout << "Projector in widescreen mode\n"; }

void Screen::down() { std::cout << "Screen going down\n"; }
void Screen::up() { std::cout << "Screen going up\n"; }

void TheaterLights::on() { std::cout << "Theater lights on\n"; }
void TheaterLights::dim(int level) { std::cout << "Theater lights dimmed to " << level << "%\n"; }

void PopcornPopper::on() { std::cout << "Popcorn popper on\n"; }
void PopcornPopper::off() { std::cout << "Popcorn popper off\n"; }
void PopcornPopper::pop() { std::cout << "Popcorn popper popping popcorn\n"; }

HomeTheaterFacade::HomeTheaterFacade(Amplifier& amp, DvdPlayer& dvd, Projector& projector,
    Screen& screen, TheaterLights& lights, PopcornPopper& popper)
    : m_amp(amp)
    , m_dvd(dvd)
    , m_projector(projector)
    , m_screen(screen)
    , m_lights(lights)
    , m_popper(popper)
{
}

void HomeTheaterFacade::watchMovie(const std::string& movie)
{
    std::cout << "Get ready to watch a movie...\n";
    m_popper.on();
    m_popper.pop();
    m_lights.dim(10);
    m_screen.down();
    m_projector.on();
    m_projector.wideScreenMode();
    m_amp.on();
    m_amp.setSurroundSound();
    m_amp.setVolume(5);
    m_dvd.on();
    m_dvd.play(movie);
}

void HomeTheaterFacade::endMovie()
{
    std::cout << "Shutting movie theater down...\n";
    m_popper.off();
    m_dvd.stop();
    m_dvd.off();
    m_amp.off();
    m_projector.off();
    m_screen.up();
    m_lights.on();
}
