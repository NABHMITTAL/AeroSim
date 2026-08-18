#include "Event.h"

namespace aerosim{
  Event::Event(eventType type):type(type){

  }

  eventType Event::getType() const{
    return type;
  }

}