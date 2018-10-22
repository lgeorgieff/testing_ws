#include "../src/engine.hpp"

#include <gtest/gtest.h>

#include <stdexcept>

const unsigned short default_horse_power{458};

class engine_f : public ::testing::Test {
 public:
  testing_sample::engine create_engine(unsigned short horse_power = default_horse_power) {
    return testing_sample::engine{horse_power};
  }

  void SetUp() override { ::testing::Test::SetUp(); }

  void TearDown() override { ::testing::Test::TearDown(); }
}; // class engine_f

TEST_F(engine_f, constructor_sets_horse_power) {
  testing_sample::engine engine{default_horse_power};
  EXPECT_EQ(engine.horse_power(), default_horse_power);
}

TEST_F(engine_f, copy_constructor_sets_horse_power) {
  testing_sample::engine engine{create_engine()};
  EXPECT_EQ(engine.horse_power(), default_horse_power);
}

TEST_F(engine_f, move_constructor_sets_horse_power) {
  testing_sample::engine engine{std::move(create_engine())};
  EXPECT_EQ(engine.horse_power(), default_horse_power);
}

TEST_F(engine_f, copy_assignment_sets_horse_power) {
  testing_sample::engine engine = create_engine();
  EXPECT_EQ(engine.horse_power(), default_horse_power);
}

TEST_F(engine_f, move_assignment_sets_horse_power) {
  testing_sample::engine engine = std::move(create_engine());
  EXPECT_EQ(engine.horse_power(), default_horse_power);
}

TEST_F(engine_f, equals_operator_returns_correct_value) {
  auto engine1{create_engine()}, engine2{create_engine(0)}, engine3{create_engine()};
  EXPECT_TRUE(engine1 == engine1);
  EXPECT_TRUE(engine1 == engine3);
  EXPECT_FALSE(engine1 == engine2);
}

TEST_F(engine_f, unequals_operator_returns_correct_value) {
  auto engine1{create_engine()}, engine2{create_engine(0)}, engine3{create_engine()};
  EXPECT_FALSE(engine1 != engine1);
  EXPECT_FALSE(engine1 != engine3);
  EXPECT_TRUE(engine1 != engine2);
}