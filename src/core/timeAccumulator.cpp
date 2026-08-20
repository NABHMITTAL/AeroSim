#include "timeAccumulator.h"

namespace aerosim{
  void TimeAccumulator::timeAdder(double delta){
    accumulatedTime+=delta;
  }

  bool TimeAccumulator::checker() const{
    return accumulatedTime >= timeStep;
  }

  void TimeAccumulator::consumer(){
    accumulatedTime-= timeStep;
  }

  double TimeAccumulator::getAccumulatedTime() const
  {
      return accumulatedTime;
  }
}