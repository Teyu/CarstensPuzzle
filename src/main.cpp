#include <iostream>
#include <random>
#include <list>

using namespace std;

int main()
{
	// assemble -> solution -------------------------------------------------------------------------------------------------
	int marker = 1;
	int solution[3][3] = {{marker, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // solution

	// disassamble -> puzzle ------------------------------------------------------------------------------------------------
	auto seed = time(0); //seed value 1704727659
	//cout << seed << endl;
	srand(time(0));

	list<int> rands;
    for(int n=0; n<9; ++n)
	{
		rands.push_back(rand()%12 + 1);
        //cout << rand()%12 + 1 << endl;
	}

	//output:
	list<int> output = {10,6,1,4,6,10,3,9,9};

	// directions: UP, DOWN, LEFT, RIGHT

	// marker starts at upper left egde -> 2 possible directions: 0 = DOWN, 1 = RIGHT
	// output[0]: 10 % 2 = 0 -> DOWN
	solution[0][0] = 4;
	solution[1][0] = marker;
	//solution = {{4, 2, 3}, {marker, 5, 6}, {7, 8, 9}};
	// marker on left edge -> 3 possible directions: 0 = UP, 1 = DOWN, 3 = RIGHT
	// output[1]: 6 % 3 = 0 -> UP
	solution[0][0] = marker;
	solution[1][0] = 4;
	// marker at upper left edge -> 2 possible directions: 0 = DOWN, 1 = RIGHT
	// output[2]: 1 % 2 = 1 -> RIGHT
	solution[0][1] = marker;
	solution[0][0] = 2;
	// marker on upper edge -> 3 possible directions: 0 = DOWN, 1 = LEFT, 2 = RIGHT
	// output[3]: 4 % 3 = 1 -> LEFT
	solution[0][0] = marker;
	solution[0][1] = 2;
	// marker at upper left edge -> 2 possible directions: 0 = DOWN, 1 = RIGHT
	// output[4]: 6 % 2 = 0 -> DOWN
	solution[1][0] = marker;
	solution[0][0] = 4;
	// marker on left edge -> 3 possible directions: 0 = UP, 1 = DOWN, 3 = RIGHT
	// output[5]: 10 % 3 = 1 -> DOWN
	solution[2][0] = marker;
	solution[1][0] = 8;
	// marker at lower left edge -> 2 possible directions: 0 = UP, 1 = RIGHT
	// output[6]: 3 % 2 = 1 -> RIGHT
	solution[2][1] = marker;
	solution[1][1] = 5;
	// marker on lower edge -> 3 possible directions: 0 = UP, 1 = LEFT, 2 = RIGHT
	// output[7]: 9 % 3 = 0 -> UP
	solution[1][1] = marker;
	solution[2][1] = 5;
	// marker at center -> 4 possible directions: 0 = UP, 1 = DOWN, 2 = LEFT, 3 = RIGHT
	// output[8]: 9 % 4 = 1 -> DOWN
	solution[2][1] = marker;
	solution[1][1] = 5;

	int puzzle[3][3] = {{4, 2, 3}, {7, 5, 6}, {8, marker, 9}}; // puzzle

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			cout << puzzle[i][j] << " ";
		cout << endl;
	}

	return 0;
}

