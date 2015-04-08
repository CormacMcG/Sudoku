/**
* This file creates a playable Sudoku game.
*
* This file creates a unique Sudoku grid with a selection of random numbers
* input into the grid along with blank spaces within the grid for the player
* to input their chosen values in order to solve the grid.
*
* @author Cormac McGarrigle <McGarrigle-C@email.ulster.ac.uk> B00585950
* @license General Public License
* @copyright Cormac McGarrigle 2015
*
* Github: https://gist.github.com/CormacMcG/1621f543d54af1df3f7e
*
*/

#include <iostream>
#include <string>
#include <cstring>
#include <time.h>

using namespace std;

// Set constant value for grid dimension variables. 
const int ROWLENGTH = 9;
const int COLUMNLENGTH = 9;

class PuzzleGenerator
{
	// Set class to public as this will need to be used in other classes.
	public:

		// Generate constructor to generate random values to be input into
		// the grid.
		PuzzleGenerator()
		{
			// Seed random value with time to ensure that it changes every 
			// time the program is run, otherwise the same numbers will appear each time.
			int seed = time(NULL);
			srand(seed);
		}
		
		// Inline GetRandomNumber function declaration (inside the PuzzleGenerator class).
		// This will generate the random number, between 1-9, for input into the grid.
		int GetRandomNumber()
		{		
			return rand() % 9 + 1;
		}
			
		// This function will populate the grid with the previously generated random numbers.
		// It will be populated starting at cell (0,0), populating the entire first row before 
		// moving onto the second column.
		void FillGrid(int grid[ROWLENGTH][COLUMNLENGTH])
		{
			// Call function from above to add the previously generated random numbers to the grid.
			for (int i = 0; i < ROWLENGTH; i++)
			{
				for (int j = 0; j < COLUMNLENGTH; j++)
				{
					// Generate a new random number.
					int randomNumber = GetRandomNumber();
					bool isUnique = CheckNumValid(randomNumber, i, j, grid);
					
					// If the newly random generated number already appears in the row/column/3*3
					// grid, ie is not unjique, generate a new random number and test if it already appears.
					while (!isUnique)
					{
						// The number already exists in the grid. Try a different one.
						randomNumber = GetRandomNumber();
						// Check if the new randomNumner is unique this time.
						isUnique = CheckNumValid(randomNumber, i, j, grid);

						// Check uniqueness test is functioning by outputting
						// the uniqueness check operation to the user.				
						if (!isUnique)
						{
						cout << "Tried number " << randomNumber << " at row " << i << ", column " 
							 << j << " but it was not unique." << endl;
						} 

						// Check what is being inserted into each grid position
						// and display to the user.
						if (isUnique)
						{
							cout << "Inserted " << randomNumber << " at row " << i << ", column "
								<< j << endl;
						}
					}

					// Now that we know the number is unique, assign it to the grid.
					grid[i][j] = randomNumber;
				}
			}
		};

		// Returns whether the given number is unique at the given position based on what 
		// numbers are already filled in.
		bool CheckNumValid(int num, int row, int column, int grid[ROWLENGTH][COLUMNLENGTH])
		{
			// Check row is valid first, by setting a boolean.
			for (int i = 0; i < 9; i++)
			{
				// Using this method the number is checked against a number within the grid. 
				// Once that number checks against itself if will always be true.

				if (i == column)
				{
					continue;
				}

				// grid[row][column]	grid[4][7]
				// grid[row][i]			grid[4][7]
				// This event previously occured meaning an infinite loop testing a number's
				// uniqueness against itself.


				// Set value for true.
				bool isCorrect = (grid[row][i] != num);

				if (!isCorrect)
				{
					return false;
				}
			}

			// Check column is valid.
			for (int i = 0; i < 9; i++)
			{
				bool isCorrect = (grid[i][column] != num);
				if (!isCorrect)
				{
					continue;
				}
			}

			return true;
		
		// Repeat the validity checks for row, this time performing them on the column.
		for (int j = 0; j < 9; j++)
				{

					if (j == row)
					{
						continue;
					}

					// Set value for true.
					bool isColCorrect = (grid[j][column] != num);

					if (!isColCorrect)
					{
						return false;
					}

				}

				// Check column is valid.
				for (int j = 0; j < 9; j++)
				{
					bool isColCorrect = (grid[row][j] != num);
					if (!isColCorrect)
					{
						continue;
					}
				}
				return true;
		}
};

			// @TODO: Repair above function for columnn check	
			// @TODO: Check the 3*3 box to ensure it contains only 1-9.

 


void main()
{
	// Initialise the grid to all zeros.
	int grid[ROWLENGTH][COLUMNLENGTH] = { 0 };
	PuzzleGenerator generator;
	// Use '.' to access fields and functions of the class.
	// Populate the grid from the randomly generated numbers.
	generator.FillGrid(grid);

 	for (int i = 0; i < ROWLENGTH; i++)
	{
		for (int j = 0; j < COLUMNLENGTH; j++)
		{
			// Display the Sudoku grid with seperated values.
			cout << grid[i][j] << "|";
		}
       
		// Create new grid line after 9 values.
		cout << endl;
	}

	// Title the game. 
	cout << " => SUDOKU - The Game of Your Life <= " << endl;
	cout << endl;

	// Introduction of game rules to the player.
	cout << " -> You will be provided with a 9*9 square board, with some numbers included." << endl;
	cout << endl;

	cout << " -> You have to arrange numbers from 1 to 9, in each row, column and 3*3 cell" << endl;
	cout << "    ensuring no repetitions of the same number" << endl;
	cout << endl;

	cout << "So, when you're ready, let's get started!" << endl;

	cout << endl;

	system("pause");

}

// Notes from research:

// Dereference a grid pointer (AKA reference) using '&'.
// The '!' character negates a boolean (true or false) statement. It is pronounced "not".
// if (false == isValid) // Ensure variable is on the left to avoid mistaken use of "=" (set value) instead of "==" (test equality).
// x = y means "set the value of x to the value of y" or "x becomes equal to y". This is a statement.
// x == y means "Does x have the same value as y?". This is a value.
