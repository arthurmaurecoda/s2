#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <string.h>

static const int LINES[8][3] = {
    {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}
};


static char winner(const char *b) {
    for (int i = 0; i < 8; i++) {
        char c = b[LINES[i][0]];
        if (c != '.' && c == b[LINES[i][1]] && c == b[LINES[i][2]])
            return c;
    }
    return strchr(b, '.') ? '-' : 'D';
}

static void show(const char *b) {
    char c[9];
    for (int i = 0; i < 9; i++) c[i] = (b[i] == '.') ? ' ' : b[i];
    printf("\n");
    for (int r = 0; r < 3; r++) {
        printf(" %c | %c | %c\n", c[r*3], c[r*3+1], c[r*3+2]);
        if (r < 2) printf("-----------\n");
    }
    printf("\n");
}

static int ask_move(const char *b, char player) {
    int move;
    for (;;) {
        printf("choisissez ou jouer (%c) : ", player);
        if (scanf("%d", &move) == 1 && move >= 0 && move <= 8 && b[move] == '.')
            return move;
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Case invalide (0-8, et libre).\n");
    }
}
#endif