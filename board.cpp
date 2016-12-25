#include <iostream>
#include "board.h"
using namespace std;

board::board(int column, int row):column(column),row(row)
{
	ary = new int*[column];
	for(int i = 0; i < column; i++)
		ary[i] = new int[row];
	for (int count_column = 0; count_column < column; count_column++)
	{
		for(int count_row = 0; count_row < row; count_row++)
		{
			ary[count_column][count_row] = 0;
		}
	}		
	ary[3][3] = 1;
	ary[3][4] = 2;
	ary[4][3] = 2;
	ary[4][4] = 1;
}

bool board::check_valid_move(int position_column, int position_row){
	if(ary[position_column][position_row] == 0)
	{
		return true;
	}	
	else 
	{
		return false;
	}	
}

bool board::check_possible_move(int position_column, int position_row){
	//check around to see if got piece 
	if(position_column < 7 && position_column > 0)
	{
		if(position_row < 7 && position_row > 0)
		{
			if(ary[position_column + 1][position_row] != 0 ||ary[position_column + 1][position_row + 1] != 0 ||ary[position_column + 1][position_row -1] != 0 || ary[position_column - 1][position_row] != 0 || ary[position_column - 1][position_row+1] != 0 || ary[position_column - 1][position_row - 1] != 0 || ary[position_column][position_row+1] != 0 || ary[position_column][position_row-1] != 0)
			{
				return true;
			}
			else
			{
				return false;
			}	
		}	
		else if(position_row == 0)
		{
			if(ary[position_column + 1][position_row] != 0 || ary[position_column + 1][position_row + 1] != 0 || ary[position_column][position_row + 1] != 0 || ary[position_column  - 1][position_row + 1] != 0 || ary[position_column - 1][position_row] != 0)
			{
				return true;
			}
			else
				return false;	
		}
		else if(position_row == 7)
		{
			if(ary[position_column + 1][position_row] != 0 || ary[position_column + 1][position_row - 1] != 0 || ary[position_column][position_row - 1] != 0 || ary[position_column  - 1][position_row - 1] != 0 || ary[position_column - 1][position_row] != 0)
			{
				return true;
			}
			else
				return false;
		}	
		else
			return false;	
	}
	else if(position_column == 0)
	{
		if(position_row < 7 && position_row > 0)
		{
			if(ary[position_column + 1][position_row] != 0 || ary[position_column + 1][position_row + 1] != 0||ary[position_column][position_row + 1] != 0||ary[position_column + 1][position_row -1] != 0||ary[position_column][position_row - 1] != 0)
			{
				return true;
			}	
			else
			{
				return false;
			}
		}
		else if(position_row == 0)
		{
			if(ary[position_column + 1][position_row] != 0||ary[position_column + 1][position_row + 1] != 0||ary[position_column][position_row + 1] != 0)
				return true;
			else
				return false;
		}	
		else if(position_row == 7)
		{
			if(ary[position_column + 1][position_row] != 0||ary[position_column + 1][position_row -1] != 0||ary[position_column][position_row - 1] != 0)
				return true;
			else 
				return false;
		}
		else
			return false;
			
	}	
	else if(position_column == 7)
	{
		if (position_row < 7 && position_row > 0) 
		{
			if(ary[position_column - 1][position_row] != 0||ary[position_column - 1][position_row + 1] != 0||ary[position_column][position_row + 1] != 0||ary[position_column - 1][position_row -1] != 0||ary[position_column][position_row - 1] != 0)
			{
				return true;
			}	
			else
			{
				return false;
			}
		}
		else if(position_row == 0)
		{
			if(ary[position_column - 1][position_row] != 0||ary[position_column - 1][position_row + 1] != 0||ary[position_column][position_row + 1] != 0)
				return true;
			else
				return false;
		}	
		else if(position_row == 7)
		{
			if(ary[position_column - 1][position_row] != 0||ary[position_column - 1][position_row -1] != 0||ary[position_column][position_row - 1] != 0)
				return true;
			else 
				return false;
		}
		else 
			return false;
	}	
	else
		return false;
}

void board::print_board(){
	cout << "  ";
	for (int count = 0; count < column; count++)
	{
		cout << count+1 << " ";
	}	
	cout << endl;
	for (int count_row = 0; count_row < row; count_row++)
		{
			cout << count_row + 1 << " ";
			for(int count_column = 0; count_column < column; count_column++)
			{
				if(ary[count_column][count_row] == 0)
					print_element = '.';
				else if(ary[count_column][count_row] == 1)
					print_element = 'w';
				else
					print_element = 'b';
				cout << print_element << " ";
			}	
			cout << endl;
		}	
}

void board::insert(int position_column, int position_row, int colour){
	ary[position_column][position_row] = colour;
}

void board::flip(int position_column, int position_row, int colour){
	// <- flipping
	valid_flip = false;
	flip_element = 100;
	for(int i = position_column-1; i >= 0; i--)
	{
		if(ary[i][position_row] == colour)
		{
			flip_element = i;
			do{
				if(ary[flip_element][position_row] == 0)
					ary[flip_element][position_row] = 0;
				else if(ary[flip_element][position_row] != colour)
				{
					ary[flip_element][position_row] = colour;
					valid_flip = true;
				}
				else 
					ary[flip_element][position_row] = colour;
				flip_element++;
				if (flip_element == position_column)
					break;
			}while(true);
		}
		if (flip_element == position_column)
			break;
		if (ary[i][position_row] == 0)
			break;
	}	
	// -> flipping
	flip_element = 100;
	for(int i = position_column+1; i < column; i++)
	{
		if(ary[i][position_row] == colour)
		{
			flip_element = i;
			do{
				if(ary[flip_element][position_row] == 0)
					ary[flip_element][position_row] = 0;
				else if(ary[flip_element][position_row] != colour)
				{
					ary[flip_element][position_row] = colour;
					valid_flip = true;
				}
				else 
					ary[flip_element][position_row] = colour;
				flip_element--;
				if (flip_element == position_column)
					break;
			}while(true);	
		}
		if (flip_element == position_column)
			break;
		if (ary[i][position_row] == 0)
			break;
	}
	// up flipping
	flip_element = 100;
	for(int i = position_row+1; i < row; i++)
	{
		if(ary[position_column][i] == colour)
		{
			flip_element = i;
			do{
				if(ary[position_column][flip_element] == 0)
					ary[position_column][flip_element] = 0;
				else if(ary[position_column][flip_element] != colour)
				{
					ary[position_column][flip_element] = colour;
					valid_flip = true;
				}
				else 
					ary[position_column][flip_element] = colour;
				flip_element--;
				if (flip_element == position_row)
					break;
			}while(true);	
		}
		if (flip_element == position_row)
			break;
		if (ary[position_column][i] == 0)
			break;
	}
	// Down flipping
	flip_element = 100;
	for(int i = position_row-1; i >= 0; i--)
	{
		if(ary[position_column][i] == colour)
		{
			flip_element = i;
			do{
				if(ary[position_column][flip_element] == 0)
					ary[position_column][flip_element] = 0;
				else if(ary[position_column][flip_element] != colour)
				{
					ary[position_column][flip_element] = colour;
					valid_flip = true;
				}	
				else 
					ary[position_column][flip_element] = colour;
				flip_element++;
				if (flip_element == position_row)
					break;
			}while(true);
		}
		if (flip_element == position_row)
			break;
		if (ary[position_column][i] == 0)
			break;
	}
	// Up right flipping
	flip_element = 100;
	int j = position_row+1;
	for(int i = position_column+1; i < column;i++)
	{
		if(ary[i][j] == colour)
		{
			flip_element = i;
			do{
				if(ary[flip_element][j] == 0)
					ary[flip_element][j] = 0;
				else if(ary[flip_element][j] != colour)
				{
					ary[flip_element][j] = colour;
					valid_flip = true;
				}	
				else 
					ary[flip_element][j] = colour;
				flip_element--;
				j--;
				if (flip_element == position_column)
					break;
			}while(true);	
		}
		if (flip_element == position_column)
			break;
		if (ary[i][j] == 0)
			break;
		j++;
		if(j > 7)
			break;
	}	
	// Up left flipping
	flip_element = 100;
	j = position_row+1;
	for(int i = position_column-1; i >= 0;i--)
	{
		if(ary[i][j] == colour)
		{
			flip_element = i;
			do{
				if(ary[flip_element][j] == 0)
					ary[flip_element][j] = 0;
				else if(ary[flip_element][j] != colour)
				{
					ary[flip_element][j] = colour;
					valid_flip = true;
				}	
				else 
					ary[flip_element][j] = colour;
				flip_element++;
				j--;
				if (flip_element == position_column)
					break;
			}while(true);	
		}
		if (flip_element == position_column)
			break;
		if (ary[i][j] == 0)
			break;
		j++;
		if(j > 7)
			break;
	}	
	//Down right flipping
	flip_element = 100;
	j = position_row-1;
	for(int i = position_column+1; i < column;i++)
	{
		if(ary[i][j] == colour)
		{
			flip_element = i;
			do{
				if(ary[flip_element][j] == 0)
					ary[flip_element][j] = 0;
				else if(ary[flip_element][j] != colour)
				{
					ary[flip_element][j] = colour;
					valid_flip = true;
				}	
				else 
					ary[flip_element][j] = colour;
				flip_element--;
				j++;
				if (flip_element == position_column)
					break;
			}while(true);	
		}
		if (flip_element == position_column)
			break;
		if (ary[i][j] == 0)
			break;
		j--;
		if(j < 0)
			break;
	}
	// Down left flipping
	flip_element = 100;
	j = position_row-1;
	for(int i = position_column-1; i >= 0;i--)
	{
		if(ary[i][j] == colour)
		{
			flip_element = i;
			do{
				if(ary[flip_element][j] == 0)
					ary[flip_element][j] = 0;
				else if(ary[flip_element][j] != colour)
				{
					ary[flip_element][j] = colour;
					valid_flip = true;
				}	
				else 
					ary[flip_element][j] = colour;
				flip_element++;
				j++;
				if (flip_element == position_column)
					break;
			}while(true);	
		}
		if (flip_element == position_column)
			break;
		if (ary[i][j] == 0)
			break;
		j--;
		if(j < 0)
			break;
	}
	

}
bool board::getValid_flip(){
	return valid_flip;
}

void board::undo(int position_column, int position_row){
	ary[position_column][position_row] = 0;
}

bool board::win_condition(int colour){
	for(int i = 0; i < column; i++){
		for(int j = 0; j < row; j++){
			if(ary[i][j] == colour){
				if(i + 4 < column){
					if(ary[i+1][j] == colour && ary[i+2][j] == colour && ary[i+3][j] == colour && ary[i+4][j] == colour){
						return true;
					}
				}
				if(i + 4 <column && j + 4 <row){
					if(ary[i+1][j+1] == colour && ary[i+2][j+2] == colour && ary[i+3][j+3] == colour && ary[i+4][j+4] == colour){
						return true;
					}
				}
				if(j + 4 <row){
					if(ary[i][j+1] == colour && ary[i][j+2] == colour && ary[i][j+3] == colour && ary[i][j+4] == colour){
						return true;
					}
				}
				if(i - 4 >=0 && j +4  <row){
					if(ary[i-1][j+1] == colour && ary[i-2][j+2] == colour && ary[i-3][j+3] == colour && ary[i-4][j+4] == colour){
						return true;
					}
				}
			}
		}
	}
	return false;
}