#ifndef CHESS_H
#define CHESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>

#define INITIAL_PIECE_COUNT 32
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8
#define BOARD_XOFFSET 6
#define BOARD_YOFFSET 4

typedef struct
{
	// Name //
	char name;
	// Positions //
	short x_pos;
	short y_pos;
} Piece;

typedef struct 	
{
	// Position // 
	short x_pos;
	short y_pos;
} Cursor;

/*
Name: 
	create_stage
Purpose:
	Sets up the physical layout of the board and initializes the indices of all of the pieces on the board. 
Parameters:
	board (char[][]) ~ The board of the pieces and their indices. 
Returns: 
	void
*/
void create_stage(char board[BOARD_HEIGHT][BOARD_WIDTH]);

/*
Name: 
	print_to_terminal
Purpose:
	Prints the board to the screen.
Parameters:
	board (char[][]) ~ The board of the pieces and their indices.
Returns:
	void
*/
void print_to_terminal(char board[BOARD_HEIGHT][BOARD_WIDTH]);

/*
Name: 
	movement
Purpose:
	
Parameters:

Returns: 

*/
void movement();

/*
Name: 
	
Purpose:
	
Parameters:
	
Returns:
	void
*/
void handle_input(char board[BOARD_HEIGHT][BOARD_WIDTH], short* pos_x, short* pos_y, char input);

#endif