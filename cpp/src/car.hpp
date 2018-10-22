#pragma once

#include "engine.hpp"

#include <cstddef>
#include <chrono>

namespace testing_sample {
class car {
 public:
  car(const engine &engine, float max_speed, float weight);
  car(const car &) = default;
  car(car &&) = default;
  car &operator=(const car &) = default;
  car &operator=(car &&) = default;
  virtual ~car() = default;

  virtual size_t vin() const = 0;
  float max_speed() const;
  void speed(float speed);
  float speed() const;
  bool is_driving() const;
  unsigned short horse_power() const;
  float average_speed() const;
  float weight() const;
  const class engine &engine() const;

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