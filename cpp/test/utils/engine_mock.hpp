#pragma once

#include "../../src/engine.hpp"

#include <gmock/gmock.h>

class engine_mock : public testing_sample::engine {
 public:
  engine_mock(float horse_power) :engine(horse_power) {}
  MOCK_CONST_METHOD0(horse_power, unsigned short());
}; // class engine_mock
