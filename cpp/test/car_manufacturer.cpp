#include "../src/four_series.hpp"
#include "../src/four_series.hpp"
#include "../src/car_manufacturer.hpp"
#include "utils/car_manufacturer_mock.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cstddef>
#include <stdexcept>

class car_manufacturer_f : public ::testing::Test {
 public:
  ~car_manufacturer_f() { TearDown(); }
  void SetUp() {}
  void TearDown() {}

  static const testing_sample::vin_pool VIN_POOL;

  virtual std::unique_ptr<testing_sample::car_manufacturer> create_instance(
      const testing_sample::vin_pool &vin_pool = VIN_POOL) const {
    return std::make_unique<car_manufacturer_mock>(vin_pool);
  }
}; // class car_base_fixture

const testing_sample::vin_pool car_manufacturer_f::VIN_POOL{1, 2, 3, 4};

TEST_F(car_manufacturer_f, can_be_instantiated) {
  auto manufacturer{create_instance()};
  SUCCEED();
}

TEST_F(car_manufacturer_f, can_create_cars_if_vin_available) {
  auto manufacturer{create_instance()};
  testing_sample::car_config config{};
  for(size_t i{0}; i < VIN_POOL.size(); ++i) manufacturer->create(config);
  SUCCEED();
}

TEST_F(car_manufacturer_f, create_fails_if_no_vin_available) {
  auto manufacturer{create_instance()};
  testing_sample::car_config config{};
  for(size_t i{0}; i < VIN_POOL.size(); ++i) manufacturer->create(config);
  EXPECT_THROW(manufacturer->create(config), std::length_error);
}