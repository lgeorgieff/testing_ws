#pragma once

#include "../../src/car.hpp"
#include "../../src/car_manufacturer.hpp"

#include <gmock/gmock.h>

#include <memory>

class car_manufacturer_mock : public testing_sample::car_manufacturer {
 public:
  car_manufacturer_mock(const testing_sample::vin_pool &vin_pool) :car_manufacturer{vin_pool} {}
  virtual std::unique_ptr<testing_sample::car> create(const testing_sample::car_config &config) override {
    next_vin();
    return std::unique_ptr<testing_sample::car>{nullptr};
  };
}; // class car_mock
