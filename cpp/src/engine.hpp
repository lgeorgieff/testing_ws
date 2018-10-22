#pragma once


namespace testing_sample {
class engine {
 public:
  explicit engine(unsigned short horse_power);
  engine(const engine &) = default;
  engine(engine &&) = default;
  engine &operator=(const engine &) = default;
  engine &operator=(engine &&) = default;
  ~engine() = default;

  bool operator==(const engine &other) const;
  bool operator!=(const engine &other) const;

  unsigned short horse_power() const;
 private:
  unsigned short horse_power_;
};
} // namespace testing_sample