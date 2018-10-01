#pragma once


namespace testing_sample {
class engine {
 public:
  engine(unsigned short horse_power) noexcept;
  engine(const engine &) = default;
  engine(engine &&) = default;
  engine &operator=(const engine &) = default;
  engine &operator=(engine &&) = default;
  ~engine() noexcept = default;

  unsigned short horse_power() const noexcept;
 private:
  unsigned short horse_power_;
};
} // namespace testing_sample