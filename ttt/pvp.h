#ifndef PVP_H
#define PVP_H
#include "common.h"

static void play_pvp(void) {
    char board[10] = ".........";
    char player = 'X';

    for (;;) {
        show(board);
        board[ask_move(board, player)] = player;

        char w = winner(board);
        if (w != '-') {
            show(board);
            if (w == 'D') printf("match nul \n");
            else          printf("%c a gagné \n", w);
            return;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

#endif