#include "bmw.hpp"

testing_sample::bmw::bmw(const class engine &engine, float max_speed, float weight, size_t vin) noexcept
  :car{engine, max_speed, weight}, vin_{vin} {}

size_t testing_sample::bmw::vin() const noexcept { return vin_; }

bool testing_sample::bmw::operator==(const testing_sample::bmw &other) const { return vin_ == other.vin_; }

bool testing_sample::bmw::operator!=(const testing_sample::bmw &other) const { return !(*this == other); }