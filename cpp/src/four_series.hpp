#include "bmw.hpp"

namespace testing_sample {
class bmw_manufacturer;

class four_series : public bmw {
 public:
  four_series(const four_series &) noexcept = default;
  four_series(four_series &&) noexcept = default;
  four_series &operator=(const four_series &) noexcept = default;
  four_series &operator=(four_series &&) noexcept = default;
  virtual ~four_series() noexcept = default;

  virtual size_t vin() const noexcept override;

 private:
  four_series(const class engine &engine, float max_speed, float weight, size_t vin) noexcept;
  friend bmw_manufacturer;
};
} // namespace testing_sample
