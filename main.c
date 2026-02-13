#include "chess.h"

int main(void)
{
	// Initialize Board //
	char board[BOARD_HEIGHT][BOARD_WIDTH];
	create_stage(board);
	// Output //
	printf("\033[2J"); // Clear screen
	print_to_terminal(board);

	char input;
	short* pos_x;
	short* pos_y;

	*pos_x = 4;
	*pos_y = 4;

	// Game playing
	while (1) {
		do {
		input = getch();
		handle_input(board, pos_x, pos_y, input);
		
		if (input == 'q') {
			exit(1);
		}

		} while (input != '\n');
	}
}