#include "utils/car_base_fixture.hpp"
#include "../src/car.hpp"
#include "../src/engine.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <memory>
#include <thread>
#include <chrono>

const auto ms_500{std::chrono::milliseconds{500}};
const auto ms_1000{std::chrono::milliseconds{1000}};

class car_f : public car_base_fixture {};

TEST_F(car_f, subclass_can_be_instantiated) {
  auto engine{create_instance()};
  auto car{create_instance(*engine)};
  EXPECT_TRUE(car);
}

TEST_F(car_f, constructor_sets_engine) {
  auto engine{create_instance()};
  auto car{create_instance(*engine)};
  EXPECT_EQ(car->engine(), *engine);
}

TEST_F(car_f, constructor_sets_max_speed) {
  auto car{create_instance(*create_instance())};
  EXPECT_EQ(car->max_speed(), MAX_SPEED);
}

TEST_F(car_f, constructor_sets_weight) {
  auto car{create_instance(*create_instance())};
  EXPECT_EQ(car->weight(), WEIGHT);
}

TEST_F(car_f, speed_is_set) {
  auto car{create_instance(*create_instance())};
  EXPECT_FLOAT_EQ(car->speed(), 0.0F);
  car->speed(123.43F);
  EXPECT_FLOAT_EQ(car->speed(), 123.43F);
}

TEST_F(car_f, speed_only_allows_valid_values) {
  auto car{create_instance(*create_instance())};
  EXPECT_THROW(car->speed(-car->max_speed() - 0.1F), std::invalid_argument);
  EXPECT_FLOAT_EQ(car->speed(), 0.0F);
  EXPECT_THROW(car->speed(car->max_speed() + 0.1F), std::invalid_argument);
  EXPECT_FLOAT_EQ(car->speed(), 0.0F);
}

TEST_F(car_f, is_driving_returns_valid_value) {
  auto car{create_instance(*create_instance())};
  EXPECT_FALSE(car->is_driving());
  car->speed(1.0F);
  EXPECT_TRUE(car->is_driving());
  car->speed(0.0F);
  EXPECT_FALSE(car->is_driving());
  car->speed(-1.0F);
  EXPECT_TRUE(car->is_driving());
  car->speed(0.0F);
  EXPECT_FALSE(car->is_driving());
}

TEST_F(car_f, horse_power_returns_value_from_engine) {
  auto car{create_instance(*create_instance())};
  EXPECT_EQ(car->horse_power(), HORSE_POWER);
}

TEST_F(car_f, average_speed_is_0_when_car_was_not_driving) {
  auto car{create_instance(*create_instance())};
  EXPECT_FLOAT_EQ(car->average_speed(), 0.0F);
}

TEST_F(car_f, average_speed_is_updated_when_car_is_driving) {
  auto car{create_instance(*create_instance())};
  std::this_thread::sleep_for(ms_500);
  EXPECT_FLOAT_EQ(car->average_speed(), 0.0F);
  car->speed(100.0F);
  std::this_thread::sleep_for(ms_500);
  EXPECT_FLOAT_EQ(car->average_speed(), 100.0F);
  car->speed(100.0F);
  std::this_thread::sleep_for(ms_500);
  EXPECT_FLOAT_EQ(car->average_speed(), 100.0F);
  car->speed(200.0F);
  std::this_thread::sleep_for(ms_1000);
  EXPECT_NEAR(car->average_speed(), (100.0F + 100.0F + 200.0F + 200.0F) / 4.0F, 0.1F);
}

TEST_F(car_f, average_speed_is_not_updated_when_car_is_not_driving) {
  auto car{create_instance(*create_instance())};
  car->speed(100.0F);
  std::this_thread::sleep_for(ms_500);
  EXPECT_FLOAT_EQ(car->average_speed(), 100.0F);
  car->speed(0.0F);
  std::this_thread::sleep_for(ms_500);
  EXPECT_FLOAT_EQ(car->average_speed(), 100.0F);
}

TEST_F(car_f, average_speed_is_updated_when_car_was_driving_and_stopping_multiple_times) {
  auto car{create_instance(*create_instance())};
  car->speed(100.0F);
  std::this_thread::sleep_for(ms_500);
  EXPECT_FLOAT_EQ(car->average_speed(), 100.0F);
  car->speed(0.0F);
  std::this_thread::sleep_for(ms_500);
  EXPECT_FLOAT_EQ(car->average_speed(), 100.0F);
  car->speed(200.0F);
  std::this_thread::sleep_for(ms_500);
  EXPECT_NEAR(car->average_speed(), (100.0F + 200.0F) / 2.0F, 0.1F);
  car->speed(0.0F);
  std::this_thread::sleep_for(ms_500);
  EXPECT_NEAR(car->average_speed(), (100.0F + 200.0F) / 2.0F, 0.1F);
  car->speed(car->max_speed());
  std::this_thread::sleep_for(ms_500);
  EXPECT_NEAR(car->average_speed(), (100.0F + 200.0F + car->max_speed()) / 3.0F, 0.1F);
}