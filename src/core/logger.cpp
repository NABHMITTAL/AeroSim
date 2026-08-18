#include "logger.h"
#include <iostream>

namespace aerosim{
  void Logger::info(const std::string& message){
    log(LogLevel::Info, message);
  }
  void Logger::warning(const std::string& message){
    log(LogLevel::Warning, message);
  }
  void Logger::error(const std::string& message){
    log(LogLevel::Error, message);
  }


  void Logger::log(LogLevel level, const std::string& message) {

    switch (level) {
      case LogLevel::Info:
        std::cout << "[INFO] " << message << '\n';
        break;

      case LogLevel::Warning:
        std::cout << "[WARNING] " << message << '\n';
        break;

      case LogLevel::Error:
        std::cout << "[ERROR] " << message << '\n';
        break;
    }
  }

}