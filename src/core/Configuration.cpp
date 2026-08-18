#include "Configuration.h"
#include <iostream>

namespace aerosim{

  Configuration::Configuration(){}
  Configuration::~Configuration(){}

  void Configuration::set(const std::string& key, const Value& value){
    values[key] = value;
  }

}
