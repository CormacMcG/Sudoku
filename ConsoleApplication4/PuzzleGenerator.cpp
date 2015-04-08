
#include <iostream>
#include <string>
#include <cstring>
#include <time.h>

using namespace std;

//Set constant value for grid dimension variables 
const int ROWLENGTH = 9;
const int COLUMNLENGTH = 9;

class PuzzleGenerator
{
public:

	//Generate constructor for random grid values
	PuzzleGenerator()
	{
		// Seed random value with time to ensure that it changes every time the program is run,
		// otherwise the same numbers will appear each time.
		int seed = time(NULL);
		srand(seed);
	}
	// Inline GetNumbers function declaration (inside the PuzzleGenerator class).
	int GetNumbers()
	{
		// TODO: Test GetNumbers by running a large loop and checking that each number is within the correct range of 1-9.

		/*for (int i = 0; i < 9; i= i++)
		{
		cout << rand() % 9 + 1 << "\n";
		}*/
		return rand() % 9 + 1;
	}


	void FillGrid(int grid[ROWLENGTH][COLUMNLENGTH])
	{
		//Call function from above to add random numbers to the grid
		for (int i = 0; i < ROWLENGTH; i++)
		{
			for (int j = 0; j < COLUMNLENGTH; j++)
			{
				int num = GetNumbers();
				grid[i][j] = num;
			}
		}
	}
};



void main()
{
	int grid[ROWLENGTH][COLUMNLENGTH];
	PuzzleGenerator generator;
	// Use '.' to access fields and functions of the class.
	generator.FillGrid(grid);

	for (int i = 0; i < ROWLENGTH; i++)
	{
		for (int j = 0; j < COLUMNLENGTH; j++)
		{
			cout << grid[i][j] << "|";
		}

		//Create new grid line after 9 values
		cout << endl;

	}

	// Title the game 
	cout << " => SUDOKU - The Game of Your Life <= " << endl;
	cout << endl;

	// Introduction of game rules to the play
	cout << " -> You will be provided with a 9*9 square board, with some numbers included." << endl;
	cout << endl;

	cout << " -> You have to arrange numbers from 1 to 9, in each row, column and 3*3 cell" << endl;
	cout << "    ensuring no repetitions of the same number" << endl;
	cout << endl;

	cout << "So, when you're ready, let's get started!" << endl;

	cout << endl;

	system("pause");

}