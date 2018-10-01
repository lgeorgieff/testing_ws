#pragma once

#include "car.hpp"
#include "engine.hpp"

namespace testing_sample {

class bmw : public car {
 public:
  bmw(const class engine &engine, float max_speed, float weight, size_t vin) noexcept;
  bmw(const bmw &) noexcept = default;
  bmw(bmw &&) noexcept = default;
  bmw &operator=(const bmw &) noexcept = default;
  bmw &operator=(bmw &&) noexcept = default;
  virtual ~bmw() noexcept = default;

  virtual size_t vin() const noexcept override = 0;

 private:
  size_t vin_;
};
} // namespace testing_sample
