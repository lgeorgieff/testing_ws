#include "bmw.hpp"

namespace testing_sample {
class bmw_manufacturer;

class eight_series : public bmw {
 public:
  eight_series(const eight_series &) noexcept = default;
  eight_series(eight_series &&) noexcept = default;
  eight_series &operator=(const eight_series &) noexcept = default;
  eight_series &operator=(eight_series &&) noexcept = default;
  virtual ~eight_series() noexcept = default;

  virtual size_t vin() const noexcept override;

 private:
  eight_series(const class engine &engine, float max_speed, float weight, size_t vin) noexcept;
  friend bmw_manufacturer;
};
} // namespace testing_sample
