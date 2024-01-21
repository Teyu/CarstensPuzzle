// Julia Michaely

#include <Randomizer.h>
#include <cstddef>
#include <random>

/////////////////////////////////////////////////////////
bool Randomizer::setMaxMinRange(int max_val, int min_val){
    if (min_val >= max_val) {
        return false;
    }
    this->min_val = min_val;
    this->max_val = max_val;

    return true;
}

/////////////////////////////////////////////////////////
std::list<int> Randomizer::createRandomNumbers(int num_numbers, int seed /* = 0*/){

    int range = max_val - min_val;

    srand(seed);

    std::list<int> randsOut{};
    for(int n=0; n<num_numbers; ++n)
    {
        int randInt = range == 0 ? 0 : rand()%range + min_val;
        randsOut.push_back(randInt);
    }

    return randsOut;
}

/////////////////////////////////////////////////////////
int Randomizer::getMinValue(){
    return min_val;
}

/////////////////////////////////////////////////////////
int Randomizer::getMaxValue(){
    return max_val;
}
