#ifndef BOARD_H
#define BOARD_H
class board{
	int column;
	int row;
	int** ary;	
	char print_element;
	int flip_element;
	bool all_possible_condition;
	bool valid_flip;
public:
	board(int column, int row);
	void print_board();
	void insert(int position_column, int position_row, int colour);
	void flip(int position_column, int position_row, int colour);
	bool check_valid_move(int position_column, int position_row);
	bool check_possible_move(int position_column, int position_row);
	bool getValid_flip();
	void undo(int position_column, int position_row);
	bool win_condition(int colour);
};

#endif