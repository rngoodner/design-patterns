#include "proxy.hpp"

#include <iostream>
#include <utility>

RealImage::RealImage(std::string filename)
    : m_filename(std::move(filename))
{
    loadFromDisk();
}

void RealImage::loadFromDisk()
{
    std::cout << "Loading " << m_filename << " from disk\n";
}

void RealImage::display() const
{
    std::cout << "Displaying " << m_filename << "\n";
}

ProxyImage::ProxyImage(std::string filename)
    : m_filename(std::move(filename))
{
}

void ProxyImage::display() const
{
    if (!m_realImage)
        m_realImage = std::make_unique<RealImage>(m_filename);
    m_realImage->display();
}
