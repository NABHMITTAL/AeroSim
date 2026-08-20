#pragma once

namespace aerosim{
  class Time{
    public:
      Time();

      double elapsedSeconds() const;
      double timeDelta(double timeEnd) const;
      double physicsStep() const;

      private:
        double startTime;
  };
}