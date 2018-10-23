#pragma once

#include "car.hpp"

#include <string>
#include <map>
#include <set>
#include <memory>

namespace testing_sample {
using car_config = std::map<std::string, std::string>;
using vin_pool = std::set<size_t>;

class car_manufacturer {
 public:
  car_manufacturer(const vin_pool &vin_pool);
  car_manufacturer(const car_manufacturer &) = default;
  car_manufacturer(car_manufacturer &&) = default;
  car_manufacturer &operator=(const car_manufacturer &) = default;
  car_manufacturer &operator=(car_manufacturer &&) = default;
  virtual ~car_manufacturer() = default;

  virtual std::unique_ptr<car> create(const car_config &config) = 0;

 protected:
  size_t next_vin();

 private:
  vin_pool vin_pool_;
};
} // namespace testing_sample
