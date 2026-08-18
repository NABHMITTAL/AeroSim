#pragma once

#include "Event.h"

namespace aerosim {

  class EventDispatcher {
  public:
    explicit EventDispatcher(Event& event);

    bool dispatch(eventType type);

  private:
    Event& event;
  };

}