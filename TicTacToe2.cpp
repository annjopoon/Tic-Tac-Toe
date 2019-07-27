// ProofOfConcept - 2D Grids.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <math.h>
#include <time.h>

using namespace std;

const int column1size = 3;
const int column2size = 3;
char tictacspace[3][3];
bool win;

void PrintBoard()
{
	for (int j = 0; j < column1size; j++)
	{
		for (int y = 0; y < column2size; y++)
		{
			cout << "[" << tictacspace[j][y] << "]";
			if (y == (column2size - 1))
			{
				cout << endl;
			}

		}
	}
}

void Check_X_Board()
{
	for (int i = 0; i <= 2; i++)
	{
		if (tictacspace[0][i] == 'X')
		{
			if (tictacspace[i][0] == tictacspace[i][1] && tictacspace[i][1] == tictacspace[i][2])
			{
				cout << "Player 1 Wins!"
					<< "\nGame is Over.";
				win = true;
			}
			else if (tictacspace[0][i] == tictacspace[1][i] && tictacspace[1][i] == tictacspace[2][i])
			{
				cout << "Player 1 Wins!"
					<< "\nGame is Over.";
				win = true;
			}
		}
	}

	if (tictacspace[0][0] == 'X' && tictacspace[1][1] == 'X' && tictacspace[2][2] == 'X' ||
		tictacspace[0][2] == 'X' && tictacspace[1][1] == 'X' && tictacspace[2][0] == 'X')
	{
		cout << "Player One Wins!"
			<< "\nGame is Over.";
		win = true;
	}
}

void Check_O_Board()
{
	for (int j = 0; j <= 2; j++)
	{
		if (tictacspace[j][1] == 'O')
		{
			if (tictacspace[j][0] == tictacspace[j][1] && tictacspace[j][1] == tictacspace[j][2])
			{
				cout << "Player 2 Wins!"
					<< "\nGame is Over.";
				win = true;
				break;
			}
			else if (tictacspace[0][j] == tictacspace[1][j] && tictacspace[1][j] == tictacspace[2][j])
			{
				cout << "Player 2 Wins!"
					<< "\nGame is Over.";
				win = true;
				break;
			}
		}
	}
	if (tictacspace[0][0] == 'O' && tictacspace[1][1] == 'O' && tictacspace[2][2] == 'O' || 
		tictacspace[0][2] == 'O' && tictacspace[1][1] == 'O' && tictacspace[2][0] == 'O')
	{
		cout << "Player Two Wins!"
			<< "\nGame is Over.";
		win = true;
	}
}

int main()
{
	int columnOptions;
	int rowOptions;
	char player1 = 'X';
	char player2 = 'O';
	bool isPlayerOne = false;
	int turnCount = 1;
	bool again;
	char answer = 'y';

	while (answer == 'y')
	{
		cout << "Tic Tac Toe\n\n";
		//For loop to make the grid
		for (int i = 0; i < column1size; i++)
		{
			for (int x = 0; x < column2size; x++)
			{
				tictacspace[i][x] = ' ';
			}
		}

		for (int j = 0; j < column1size; j++)
		{
			for (int y = 0; y < column2size; y++)
			{
				cout << "[" << tictacspace[j][y] << "]";
				if (y == (column2size - 1))
				{
					cout << endl;
				}

			}
		}
		//User Input
		win = false;
		while (!win)
		{
			cout << "\nPlayer Turn:"
				<< "\nEnter row number: ";
			cin >> rowOptions;
			while (rowOptions > 3 || rowOptions <= 0)
			{
				cout << "That is not a valid row number. Please re-enter: ";
				cin >> rowOptions;
			}
			cout << "\nEnter column number: ";
			cin >> columnOptions;
			while (columnOptions > 3 || columnOptions <= 0)
			{
				cout << "That is not a valid column number. Please re-enter: ";
				cin >> columnOptions;
			}
			while ((tictacspace[rowOptions - 1][columnOptions - 1] == 'X') or (tictacspace[rowOptions - 1][columnOptions - 1] == 'O'))
			{
				cout << "That space is already taken. Please re-enter a new location: ";
				cin >> rowOptions;
				while (rowOptions > 3 || rowOptions <= 0)
				{
					cout << "That is not a valid row number. Please re-enter: ";
					cin >> rowOptions;
				}
				cout << "\nEnter column number: ";
				cin >> columnOptions;
				while (columnOptions > 3 || columnOptions <= 0)
				{
					cout << "That is not a valid column number. Please re-enter: ";
					cin >> columnOptions;
				}
			}

			system("cls");
			isPlayerOne = (turnCount % 2 == 1) ? true : false;

			Check_X_Board();
			Check_O_Board();

			;		if (turnCount > 9)
			{
				cout << "End of Game.";
				win = true;
			}

		}
		cout << "Would you like to play another game? (Y/N)";
		cin >> answer;
	}

}
