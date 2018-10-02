#include "../src/engine.hpp"

#include <gtest/gtest.h>

#include <utility>

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
  EXPECT_EQ(default_horse_power, engine.horse_power());
}

TEST_F(engine_f, copy_constructor_sets_horse_power) {
  testing_sample::engine engine{create_engine()};
  EXPECT_EQ(default_horse_power, engine.horse_power());
}

TEST_F(engine_f, move_constructor_sets_horse_power) {
  testing_sample::engine engine{std::move(create_engine())};
  EXPECT_EQ(default_horse_power, engine.horse_power());
}

TEST_F(engine_f, copy_assignment_sets_horse_power) {
  testing_sample::engine engine = create_engine();
  EXPECT_EQ(default_horse_power, engine.horse_power());
}

TEST_F(engine_f, move_assignment_sets_horse_power) {
  testing_sample::engine engine = std::move(create_engine());
  EXPECT_EQ(default_horse_power, engine.horse_power());
}
