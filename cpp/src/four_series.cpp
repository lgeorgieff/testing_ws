#include "four_series.hpp"

testing_sample::four_series::four_series(const testing_sample::engine &engine, float max_speed, float weight, size_t vin)
    :bmw{engine, max_speed, weight, vin} {}

size_t testing_sample::four_series::vin() const { return bmw::vin(); }
