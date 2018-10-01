#include "bmw.hpp"

testing_sample::bmw::bmw(const class engine &engine, float max_speed, float weight, size_t vin) noexcept
  :car{engine, max_speed, weight}, vin_{vin} {}

size_t testing_sample::bmw::vin() const noexcept { return vin_; }
