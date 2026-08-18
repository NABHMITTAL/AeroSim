#pragma once

#include <string>
#include <unordered_map>
#include <variant>

namespace aerosim{
  class Configuration{
    public:
      using Value = std::variant<int, float, bool, std::string>;

      Configuration();
      ~Configuration();

      void set(const std::string& key, const Value& value);
      template<typename T>
      T get(const std::string& key) const{
        return std::get<T>(values.at(key));
      };
    private:
      std::unordered_map<std::string, Value> values;

  };
}