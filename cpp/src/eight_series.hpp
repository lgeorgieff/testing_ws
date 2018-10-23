#pragma once

#include "bmw.hpp"

namespace testing_sample {
class bmw_manufacturer;

class eight_series : public bmw {
 public:
  eight_series(const eight_series &) = default;
  eight_series(eight_series &&) = default;
  eight_series &operator=(const eight_series &) = default;
  eight_series &operator=(eight_series &&) = default;
  virtual ~eight_series() = default;

  virtual size_t vin() const override;

 protected:
  eight_series(const testing_sample::engine &engine, float max_speed, float weight, size_t vin);
  friend bmw_manufacturer;
};
} // namespace testing_sample
