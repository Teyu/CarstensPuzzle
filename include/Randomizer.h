// Julia Michaely

#include<list>

#ifndef RANDOMIZER_H
#define RANDOMIZER_H

  class Randomizer{
    public:
      bool setMaxMinRange(int max_val, int min_val);
      std::list<int> createRandomNumbers(int num_numbers, int seed = 0);
      int getMinValue();
      int getMaxValue();
    private:
      int min_val = 0;
      int max_val = 0;
  };

#endif // RANDOMIZER_H