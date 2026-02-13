#include "chess.h"

/*
Cursor Left: \033[C
Cursor Right: \033[D
\033[25;1H" move cursor to row 25 col 1
*/

void handle_input(char board[BOARD_HEIGHT][BOARD_WIDTH], int* pos_x, int* pos_y, char input)
{
    switch (input)
    {
    case 'a': 
    case 'A':
        //if ()
        printf("\033[C");
        printf("\033[C"); // Twice because there is there a space between the characters
        (*pos_x)--;
        break;
    case 'd':
    case 'D':
        //if ()
        printf("\033[D");
        printf("\033[D");
        (*pos_x)++;
        break;
    }   
}