#ifndef CHESS_H
#define CHESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#ifdef _WIN32
    #include <conio.h>  // Use the native Windows library
#else
    #include "posix_input.h" // Use our custom UNIX definition for Windows equivalent functions
#endif

#define EMPTY_SQUARE '#'
#define MOVE_SQUARE '@'
#define CAPTURE_SQUARE '!'

#define INITIAL_PIECE_COUNT 32
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8
#define BOARD_XOFFSET 6
#define BOARD_YOFFSET 3

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct{
	// Name //
	char name;
	// Positions //
	short x_pos;
	short y_pos;
} Piece;

typedef struct {
	Piece piece;
	bool first_move;
} Pawn;

typedef struct {
	Piece piece;
	// Will prbably need other variables to deal with checks + checkmate
} King;

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
void create_stage(char board[BOARD_HEIGHT][BOARD_WIDTH], Piece pieces[INITIAL_PIECE_COUNT]);

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
	
Purpose:
	
Parameters:
	
Returns:
	void
*/
void handle_input(char board[BOARD_HEIGHT][BOARD_WIDTH], short* pos_x, short* pos_y, char input, char* current_piece);

char select_square(char board[BOARD_HEIGHT][BOARD_WIDTH], short pos_x, short pos_y, char* current_piece);

void whitePawnSelected(char board[BOARD_HEIGHT][BOARD_WIDTH], short pos_x, short pos_y);

void blackPawnSelected(char board[BOARD_HEIGHT][BOARD_WIDTH], short pos_x, short pos_y);

#endif