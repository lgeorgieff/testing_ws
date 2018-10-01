#include "car_manufacturer.hpp"

#include <stdexcept>

testing_sample::car_manufacturer::car_manufacturer(const vin_pool &vin_pool) :vin_pool_{vin_pool} {}

std::unique_ptr<testing_sample::car> testing_sample::car_manufacturer::create(const testing_sample::car_config &config) {
  throw std::runtime_error{"Method not implemented in abstract class"};
}

size_t testing_sample::car_manufacturer::next_vin() {
  if(vin_pool_.empty()) throw std::length_error{"No more VINs available"};
  auto vin{*vin_pool_.begin()};
  vin_pool_.erase(vin_pool_.begin());
  return vin;
}