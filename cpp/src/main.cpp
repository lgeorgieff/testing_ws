#include "bmw_manufacturer.hpp"

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <stdexcept>

using std::cout, std::cerr, std::endl;
using std::vector;

using testing_sample::bmw_manufacturer;
using testing_sample::vin_pool;
using testing_sample::car_config;

int main() {
  bmw_manufacturer bmw{vin_pool{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
  car_config config8;
  config8.insert(std::pair("series", "8"));
  config8.insert(std::pair("engine", "50"));

  for(size_t counter{0}; counter < 11; ++counter) {
    try {
      auto car{bmw.create(config8)};
      if (counter == 0) {
        car->speed(120);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        car->speed(60);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        car->speed(0);
      }
      cout << "VIN: " << car->vin() << ", average speed: " << car->average_speed() << endl;
    } catch(std::length_error &error) {
      cerr << error.what() << endl;
      break;
    }
  }

  return 0;
}
