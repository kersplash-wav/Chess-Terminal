#include "chess.h"

void create_stage(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    char board_cache[BOARD_HEIGHT][BOARD_WIDTH] =
    {
        {'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'} 
    };

    memcpy(board, board_cache, sizeof(char)*(BOARD_HEIGHT * BOARD_WIDTH));
}

void print_to_terminal(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    // Top of the Board //
    printf("     a b c d e f g h     \n");
    printf("   +-----------------+   \n");
    // Iterate Through Grid //
    for (int x = 0; x < BOARD_HEIGHT; x++)
    {
        printf(" %d | ", BOARD_HEIGHT - x);
        // Print Columns //
        for (int y = 0; y < BOARD_WIDTH; y++)
            printf("%c ", board[x][y]);
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