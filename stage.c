#include "chess.h"

void create_stage(char board[BOARD_HEIGHT][BOARD_WIDTH], Piece pieces[INITIAL_PIECE_COUNT])
{
    char board_cache[BOARD_HEIGHT][BOARD_WIDTH] =
    {
        {'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
        {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
        {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
        {EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE, EMPTY_SQUARE},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'} 
    };

    memcpy(board, board_cache, sizeof(char)*(BOARD_HEIGHT * BOARD_WIDTH));

    int index = 0;
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == EMPTY_SQUARE) continue;
            pieces[index].name = board[i][j];
            pieces[index].x_pos = j;
            pieces[index].y_pos = i;
            index++;
        }
    }
}

void print_to_terminal(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    printf("\033[2J"); // Clear screen
    printf("\n");

    // Top of the Board //
    printf("     a b c d e f g h     \n");
    printf("   +-----------------+   \n");
    // Iterate Through Grid //
    for (int x = 0; x < BOARD_HEIGHT; x++)
    {
        printf(" %d | ", BOARD_HEIGHT - x);
        // Print Columns //
        for (int y = 0; y < BOARD_WIDTH; y++) {
            if (board[x][y] == MOVE_SQUARE) {
                printf(ANSI_COLOR_GREEN "@ " ANSI_COLOR_RESET);
                continue;
            }
            if (board[x][y] >= 'A' && board[x][y] <= 'Z') {
                printf(ANSI_COLOR_BLUE "%c " ANSI_COLOR_RESET, board[x][y]);
                continue;
            }
            if (board[x][y] >= 'a' && board[x][y] <= 'z') {
                printf(ANSI_COLOR_RED "%c " ANSI_COLOR_RESET, board[x][y]);
                continue;
            }
            if (board[x][y] == CAPTURE_SQUARE) {
                printf(ANSI_COLOR_YELLOW "! " ANSI_COLOR_RESET);
                continue;
            }
            printf("%c ", board[x][y]);
        }
        // New Row //
        printf("| %d\n", BOARD_HEIGHT - x);
    }
    // Bottom of the Board //
    printf("   +-----------------+   \n");
    printf("     a b c d e f g h     \n");

    printf("\033[");
}

void movement() {

}

/*

     a b c d e f g h     \n
   +-----------------+   \n
 8 | r n b q k b n r | 8 \n
 7 | p p p p p p p p | 7 \n
 6 | # # # # # # # # | 6 \n
 5 | # # # # # # # # | 5 \n
 4 | # # # # # # # # | 4 \n
 3 | # # # # # # # # | 3 \n
 2 | P P P P P P P P | 2 \n
 1 | R N B Q K B N R | 1 \n
   +-----------------+   \n
     a b c d e f g h     \n

*/