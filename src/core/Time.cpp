#include "Time.h"
#include "timeAccumulator.h"

#include <chrono>

namespace aerosim {

    Time::Time(): startTime(std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count()){}

    double Time::elapsedSeconds() const{
        double currentTime =std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();

        return currentTime - startTime;
    }



    double Time::timeDelta(double timeEnd) const{
        return this->elapsedSeconds() - timeEnd;
    }

}