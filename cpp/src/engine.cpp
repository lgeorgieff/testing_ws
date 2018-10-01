#include "engine.hpp"

testing_sample::engine::engine(unsigned short horse_power) noexcept :horse_power_{horse_power} {}

unsigned short testing_sample::engine::horse_power() const noexcept { return horse_power_; }
