#include "car.hpp"

#include <string>
#include <stdexcept>

using milliseconds = std::chrono::milliseconds;
using std::chrono::system_clock;
using std::chrono::duration_cast;

testing_sample::car::car(const testing_sample::engine &engine, float max_speed, float weight)
  :engine_{engine}, max_speed_{max_speed}, weight_{weight}, speed_{0}, speed_time_stamp_{0}, average_speed_{0.0F},
  average_speed_interval_{0} {}

size_t testing_sample::car::vin() const { return 0; }

float testing_sample::car::max_speed() const { return max_speed_; }

void testing_sample::car::speed(float speed) {
  if(speed > max_speed_ || speed < -max_speed_) {
    throw std::invalid_argument{
        "invalid speed (" + std::to_string(speed) + ") value (max_speed: " + std::to_string(max_speed_) + ")"};
  }

  if(speed_) {
    milliseconds
        current_period{duration_cast<milliseconds>(system_clock::now().time_since_epoch() - speed_time_stamp_)};
    average_speed_ = ((average_speed_ * average_speed_interval_) + (speed_ * current_period))
        / (average_speed_interval_ + current_period);
    average_speed_interval_ += current_period;
  }

  speed_ = speed;
  speed_time_stamp_ = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()
      .time_since_epoch());
}

float testing_sample::car::speed() const {
  return speed_;
}

bool testing_sample::car::is_driving() const { return speed_; }

unsigned short testing_sample::car::horse_power() const { return engine_.horse_power(); }

float testing_sample::car::average_speed() const {
  auto result{average_speed_};
  if(speed_) {
    milliseconds
        current_period{duration_cast<milliseconds>(system_clock::now().time_since_epoch() - speed_time_stamp_)};
    result = ((average_speed_ * average_speed_interval_) + (speed_ * current_period))
        / (average_speed_interval_ + current_period);
  }
  return result;
}

float testing_sample::car::weight() const { return weight_; }

const testing_sample::engine &testing_sample::car::engine() const { return engine_; }
