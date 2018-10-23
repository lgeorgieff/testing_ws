#include "bmw.hpp"

namespace testing_sample {
class bmw_manufacturer;

class four_series : public bmw {
 public:
  four_series(const four_series &) = default;
  four_series(four_series &&) = default;
  four_series &operator=(const four_series &) = default;
  four_series &operator=(four_series &&) = default;
  virtual ~four_series() = default;

  virtual size_t vin() const override;

 protected:
  four_series(const testing_sample::engine &engine, float max_speed, float weight, size_t vin);
  friend bmw_manufacturer;
};
} // namespace testing_sample
