#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static inline int getch(void) {
    struct termios oldt, newt;
    int ch;

    // 1. Get current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // 2. Disable buffered I/O (ICANON) and local echo (ECHO)
    newt.c_lflag &= ~(ICANON | ECHO);

    // 3. Apply new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // 4. Read the character
    ch = getchar();

    // 5. Restore old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}