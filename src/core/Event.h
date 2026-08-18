#pragma once
#include "EventType.h"

namespace aerosim{
  class Event{
    public:
      explicit Event(eventType type);
      eventType getType() const;
    private:
      eventType type;
  };
}