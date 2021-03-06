#pragma once

#include "car_manufacturer.hpp"

namespace testing_sample {
class bmw_manufacturer : public car_manufacturer {
 public:
  explicit bmw_manufacturer(const vin_pool &vin_pool);
  bmw_manufacturer(const bmw_manufacturer &) = default;
  bmw_manufacturer(bmw_manufacturer &&)  = default;
  bmw_manufacturer &operator=(const bmw_manufacturer &) = default;
  bmw_manufacturer &operator=(bmw_manufacturer &&) = default;
  virtual ~bmw_manufacturer() = default;

  virtual std::unique_ptr<car> create(const car_config &config);
};
} // namespace testing_sample