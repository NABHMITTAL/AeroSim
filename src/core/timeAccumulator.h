#pragma once

namespace aerosim{
  class TimeAccumulator
  {
    double timeStep = 0.01;
    double accumulatedTime = 0.0;
  public:
    bool checker() const;
    void timeAdder(double delta);
    void consumer();
    double getAccumulatedTime() const;
  };
  
}