#include "core/Time.h"
#include "core/TimeAccumulator.h"

#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    aerosim::Time timer;
    aerosim::TimeAccumulator accumulator;

    double previousTime = timer.elapsedSeconds();

    int physicsSteps = 0;

    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(5)
        );

        double currentTime = timer.elapsedSeconds();

        double deltaTime = currentTime - previousTime;

        previousTime = currentTime;

        accumulator.timeAdder(deltaTime);

        while (accumulator.checker())
        {
            physicsSteps++;

            accumulator.consumer();

            std::cout << "Physics step: "
                    << physicsSteps
                    << " | Excess time: "
                    << accumulator.getAccumulatedTime()
                    << " seconds\n";
        }
    }

    std::cout << "Total physics steps: "
              << physicsSteps
              << "\n"
              << accumulator.getAccumulatedTime();

    return 0;
}