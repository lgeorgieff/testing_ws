#include "engine.hpp"

testing_sample::engine::engine(unsigned short horse_power) :horse_power_{horse_power} {}

unsigned short testing_sample::engine::horse_power() const { return horse_power_; }

bool testing_sample::engine::operator==(const engine &other) const { return horse_power_ == other.horse_power_; }

bool testing_sample::engine::operator!=(const engine &other) const { return !(*this == other); }