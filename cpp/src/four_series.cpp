#include "four_series.hpp"

testing_sample::four_series::four_series(const class engine &engine, float max_speed, float weight, size_t vin) noexcept
    :bmw{engine, max_speed, weight, vin} {}

size_t testing_sample::four_series::vin() const noexcept { return bmw::vin(); }
