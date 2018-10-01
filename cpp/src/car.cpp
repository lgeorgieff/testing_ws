#include "car.hpp"

#include <string>
#include <stdexcept>

namespace {
using milliseconds = std::chrono::milliseconds;
using std::chrono::system_clock;
using std::chrono::duration_cast;

void update_average_speed(float &average_speed, milliseconds &average_period, float speed, milliseconds &time_stamp) {
    if(speed == 0) return;

    milliseconds current_period{duration_cast<milliseconds >(system_clock::now().time_since_epoch() - time_stamp)};
    average_speed = ((average_speed * average_period) + (speed * current_period)) / (average_period + current_period);
    average_period += current_period;
}

float calculate_average_speed(float average_speed, const milliseconds &average_period, float speed, const milliseconds &time_stamp) {
  if(speed == 0) return average_speed;

  milliseconds current_period{duration_cast<milliseconds >(system_clock::now().time_since_epoch() - time_stamp)};
  average_speed = ((average_speed * average_period) + (speed * current_period)) / (average_period + current_period);
  return average_speed;
}
} // anonymous namespace

testing_sample::car::car(const testing_sample::engine &engine, float max_speed, float weight) noexcept
  :engine_{engine}, max_speed_{max_speed}, weight_{weight}, speed_{0}, speed_time_stamp_{0}, average_speed_{0.0F},
  average_speed_interval_{0} {}

size_t testing_sample::car::vin() const noexcept { return 0; }

float testing_sample::car::max_speed() const noexcept { return max_speed_; }

void testing_sample::car::speed(float speed) {
  if(speed > max_speed_ || speed < -max_speed_) {
    throw std::invalid_argument{
        "invalid speed (" + std::to_string(speed) + ") value (max_speed: " + std::to_string(max_speed_) + ")"};
  }

  update_average_speed(average_speed_, average_speed_interval_, speed_, speed_time_stamp_);
  speed_ = speed;
  speed_time_stamp_ = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()
      .time_since_epoch());
}

float testing_sample::car::speed() const noexcept {
  return speed_;
}

bool testing_sample::car::is_driving() const noexcept { return speed_; }

unsigned short testing_sample::car::horse_power() const noexcept { return engine_.horse_power(); }

float testing_sample::car::average_speed() const noexcept {
  calculate_average_speed(average_speed_, average_speed_interval_, speed_, speed_time_stamp_);
  return average_speed_;
}

float testing_sample::car::weight() const noexcept { return weight_; }

const testing_sample::engine &testing_sample::car::engine() const noexcept { return engine_; }