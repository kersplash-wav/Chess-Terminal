#include "chess.h"

int main(void)
{
	// Initialize Board //
	char board[BOARD_HEIGHT][BOARD_WIDTH];
	create_stage(board);
	// Output //
	print_to_terminal(board);

	char input;
	int* pos_x;
	int* pos_y;

	*pos_x = 4;
	*pos_y = 4;

	// Game playing
	while (1) {
		do {
		handle_input(board, pos_x, pos_y, getch());
		
		if (input == '0') {
			break;
		}

		} while (input != '\n');
	}
}