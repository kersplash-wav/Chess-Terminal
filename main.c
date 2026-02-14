#include "chess.h"

int main(void)
{
	// Initialize Board //
	char board[BOARD_HEIGHT][BOARD_WIDTH];
	Piece pieces[INITIAL_PIECE_COUNT];
	create_stage(board, pieces);
	// Output //
	print_to_terminal(board);

	char input;
	short pos_x = 4;
	short pos_y = 4;
	char current_piece;

	// Game playing
	while (1) {
		input = getch();
		handle_input(board, &pos_x, &pos_y, input, &current_piece);
		
		if (input == 'q') {
			exit(0);
		}
	}
}