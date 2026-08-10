#include "Application.h"

#include <iostream>

namespace aerosim{

  Application::Application(){
    
  }

  Application::~Application(){

  }

  void Application::run(){
      std::cout << "AeroSIM application running.\n";
  }

}