#include "../src/four_series.hpp"
#include "../src/eight_series.hpp"
#include "../src/bmw.hpp"
#include "../src/bmw_manufacturer.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cstddef>
#include <utility>
#include <stdexcept>

class bmw_manufacturer_f : public ::testing::Test {
 public:
  ~bmw_manufacturer_f() { TearDown(); }
  void SetUp() {}
  void TearDown() {}

  static const testing_sample::vin_pool VIN_POOL;

  testing_sample::car_config config(const std::string &series, const std::string &engine) const {
    testing_sample::car_config config{
      std::pair("series", series),
      std::pair("engine", engine)
    };

    return config;
  }

  virtual std::unique_ptr<testing_sample::bmw_manufacturer> create_instance(
      const testing_sample::vin_pool &vin_pool = VIN_POOL) const {
    return std::make_unique<testing_sample::bmw_manufacturer>(vin_pool);
  }
}; // class bmw_manufacturer_f

const testing_sample::vin_pool bmw_manufacturer_f::VIN_POOL{1, 2, 3, 4};

TEST_F(bmw_manufacturer_f, is_instantiated) {
  auto manufacturer{create_instance()};
  EXPECT_TRUE(manufacturer);
}

TEST_F(bmw_manufacturer_f, creates_four_series) {
  auto manufacturer{create_instance()};
  auto bmw{manufacturer->create(config("4", "30"))};
  EXPECT_TRUE(bmw);
  EXPECT_TRUE(typeid(*bmw) == typeid(testing_sample::four_series));
  EXPECT_EQ(bmw->horse_power(), 252);
  EXPECT_FLOAT_EQ(bmw->max_speed(), 250.0F);
  EXPECT_FLOAT_EQ(bmw->weight(), 1585);

  bmw = manufacturer->create(config("4", "40"));
  EXPECT_TRUE(bmw);
  EXPECT_TRUE(typeid(*bmw) == typeid(testing_sample::four_series));
  EXPECT_EQ(bmw->horse_power(), 326);
  EXPECT_FLOAT_EQ(bmw->max_speed(), 250.0F);
  EXPECT_FLOAT_EQ(bmw->weight(), 1630);
}

TEST_F(bmw_manufacturer_f, throws_if_wrong_four_series_config) {
  auto manufacturer{create_instance()};
  EXPECT_THROW(manufacturer->create(config("4", "10")), std::invalid_argument);
}

TEST_F(bmw_manufacturer_f, creates_eight_series) {
  auto manufacturer{create_instance()};
  auto bmw{manufacturer->create(config("8", "50"))};
  EXPECT_TRUE(bmw);
  EXPECT_TRUE(typeid(*bmw) == typeid(testing_sample::eight_series));
  EXPECT_EQ(bmw->horse_power(), 523);
  EXPECT_FLOAT_EQ(bmw->max_speed(), 250.0F);
  EXPECT_FLOAT_EQ(bmw->weight(), 1965);
}

TEST_F(bmw_manufacturer_f, throws_if_wrong_eight_series_config) {
  auto manufacturer{create_instance()};
  EXPECT_THROW(manufacturer->create(config("8", "10")), std::invalid_argument);
}

TEST_F(bmw_manufacturer_f, throws_if_wrong_series_in_config) {
  auto manufacturer{create_instance()};
  EXPECT_THROW(manufacturer->create(config("9", "10")), std::invalid_argument);
}