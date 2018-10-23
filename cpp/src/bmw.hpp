#pragma once

#include "car.hpp"
#include "engine.hpp"

namespace testing_sample {

class bmw : public car {
 public:
  bmw(const class engine &engine, float max_speed, float weight, size_t vin);
  bmw(const bmw &) = default;
  bmw(bmw &&) = default;
  bmw &operator=(const bmw &) = default;
  bmw &operator=(bmw &&) = default;
  virtual ~bmw() = default;

  virtual size_t vin() const override = 0;
  bool operator==(const bmw &other) const;
  bool operator!=(const bmw &other) const;
 private:
  size_t vin_;
};
} // namespace testing_sample
