// Julia Michaely

#include<list>

#ifndef RANDOMIZER_H
#define RANDOMIZER_H

  class Randomizer{
    public:
      Randomizer() : min_val(0), max_val(0) {};
      Randomizer(Randomizer const &other) {
          this->min_val = other.min_val;
          this->max_val = other.max_val;
      }
      bool setMaxMinRange(int max_val, int min_val);
      virtual std::list<int> createRandomNumbers(int num_numbers, int seed = 0);
      int getMinValue();
      int getMaxValue();
      virtual ~Randomizer() = default;
    private:
      int min_val = 0;
      int max_val = 0;
  };

#endif // RANDOMIZER_H
