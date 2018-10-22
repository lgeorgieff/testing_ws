#pragma once

#include "../../src/car.hpp"
#include "../../src/engine.hpp"

#include <gmock/gmock.h>

class car_mock : public testing_sample::car {
 public:
  car_mock(const testing_sample::engine &engine, float max_speed, float weight) noexcept
      :car{engine, max_speed, weight} {}
  virtual size_t vin() const noexcept override {
    return 123;
  }
}; // class car_mock