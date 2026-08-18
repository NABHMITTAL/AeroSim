#include "core/EventDispatcher.h"

#include <iostream>

int main()
{
    aerosim::Event event(aerosim::eventType::WindowClose);

    aerosim::EventDispatcher dispatcher(event);

    bool handled = dispatcher.dispatch(
        aerosim::eventType::WindowClose
    );

    std::cout << "Event handled: "
        << std::boolalpha
        << handled
        << '\n';

    return 0;
}