#pragma once

#include "engine.hpp"

#include <cstddef>
#include <chrono>

namespace testing_sample {
class car {
 public:
  car(const engine &engine, float max_speed, float weight) noexcept;
  car(const car &) = default;
  car(car &&) = default;
  car &operator=(const car &) = default;
  car &operator=(car &&) = default;
  virtual ~car() noexcept = default;

  virtual size_t vin() const noexcept = 0;
  float max_speed() const noexcept;
  void speed(float speed);
  float speed() const noexcept;
  bool is_driving() const noexcept;
  unsigned short horse_power() const noexcept;
  float average_speed() const noexcept;
  float weight() const noexcept;
  const engine &engine() const noexcept;

 private:
  class engine engine_;
  float max_speed_;
  float weight_;
  float speed_;
  std::chrono::milliseconds speed_time_stamp_;
  float average_speed_;
  std::chrono::milliseconds average_speed_interval_;
};
} // namespace testing_sample