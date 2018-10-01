#include "bmw_manufacturer.hpp"
#include "bmw.hpp"
#include "four_series.hpp"
#include "eight_series.hpp"

#include <stdexcept>

testing_sample::bmw_manufacturer::bmw_manufacturer(const vin_pool &vin_pool) :car_manufacturer{vin_pool} {}

std::unique_ptr<testing_sample::car> testing_sample::bmw_manufacturer::create(const car_config &config) {
  if(config.find("series") == config.end()) throw std::invalid_argument{"config misses \"series\" specification"};
  if(config.find("engine") == config.end()) throw std::invalid_argument{"config misses \"engine\" specification"};

  bmw *bmw{nullptr};
  if(config.find("series")->second == "8") {
    unsigned short horse_power{0};
    float max_speed{0};
    float weight{0};
    if(config.find("engine")->second == "50") {
      horse_power = 523;
      max_speed = 250;
      weight = 1965;
    } else {
      throw std::invalid_argument{"series must be \"50\" for 8 series"};
    }
    bmw = new eight_series{engine{horse_power}, max_speed, weight, next_vin()};
  } else if(config.find("series")->second == "4") {
    unsigned short horse_power{0};
    float max_speed{0};
    float weight{0};
    if(config.find("engine")->second == "30") {
      horse_power = 252;
      max_speed = 250;
      weight = 1585;
    } else if(config.find("engine")->second == "40")  {
      horse_power = 326;
      max_speed = 250;
      weight = 1630;
    } else {
      throw std::invalid_argument{"series must be on of \"30\", \"40\" four 4 series"};
    }
    bmw = new four_series{engine{horse_power}, max_speed, weight, next_vin()};
  } else {
    throw std::invalid_argument{"series must be on of \"4\", \"8\""};
  }

  return std::unique_ptr<car>{bmw};
}