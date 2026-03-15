#include "proxy.hpp"

int main()
{
    // proxy defers disk load until display() is first called
    ProxyImage proxy { "photo.jpg" };

    proxy.display(); // loads from disk, then displays
    proxy.display(); // already loaded; displays directly
}
