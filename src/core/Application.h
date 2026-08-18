#pragma once

namespace aerosim{

  class Application{
  public:
    Application();
    ~Application();

    void initialize();
    void run();
    void shutDown();
  };

}