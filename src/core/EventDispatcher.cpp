#include "EventDispatcher.h"

namespace aerosim {

  EventDispatcher::EventDispatcher(Event& event): event(event){
  }

  bool EventDispatcher::dispatch(eventType type){
    if (event.getType() == type){
      return true;
    }

    return false;
  }

}