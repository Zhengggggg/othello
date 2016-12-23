#include <iostream>
#include <string>
#include <sstream>
#include "stdlib.h"
#include "board.cpp"
#include "error_handling.cpp"
using namespace std;

int main()
{
	int turn = 1,position_column,position_row,colour = 0;
	string input;
	board othello(8,8);
	othello.print_board();
	for(int i = 0 ; i < 64; i++)
	{
		do{
			try{
				cout << "\nEnter the position(column): ";
				cin.sync();
				cin >> input;
				if(!(istringstream (input) >> position_column))
					throw error_handling("Error: It is not an integer\n");
				if(position_column > 8 || position_column < 1)
				{
					throw error_handling("Error: It is not in range\n");
				}	
				break;
			}
			catch(error_handling e)
			{
				cout << e.getMessage();
			}
		}while(true);
		do{
			try{
				cout << "\nEnter the position(row): ";
				cin.sync();
				cin >> input;
				if(!(istringstream (input) >> position_row))
					throw error_handling("Error: It is not an integer\n");
				if(position_row > 8 || position_row < 1)
				{
					throw error_handling("Error: It is not in range\n");
				}	
				break;
			}
			catch(error_handling e)
			{
				cout << e.getMessage();
			}
		}while(true);
		position_column--;
		position_row--;
		colour = (turn % 2) + 1;
		if(othello.check_valid_move(position_column,position_row) == true && othello.check_possible_move(position_column,position_row) == true)
		{
			othello.insert(position_column,position_row,colour);
			othello.flip(position_column,position_row,colour);
			if(othello.getValid_flip() != true)
			{
				othello.undo(position_column,position_row);
				cout << "Invalid Input!" << endl;
				turn--;
				system("pause");
			}
		}	
		else
		{
			cout << "Invalid Input!" << endl;
			turn--;
			system("pause");
		}	
		system("cls");
		othello.print_board();
		turn++;
	}
}
