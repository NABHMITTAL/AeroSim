#include "Application.h"
#include <iostream>
#include "logger.h"

namespace aerosim {

    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::initialize() {
      Logger::info("AeroSim Initializing...");
    }
    void Application::run() {
      Logger::info("AeroSIM application running...");
    }
    void Application::shutDown() {
      Logger::info("AeroSIM Shutting Down...");

    }

}