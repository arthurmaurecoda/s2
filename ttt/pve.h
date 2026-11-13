#ifndef PVE_H
#define PVE_H
#include <stdlib.h>
#include "common.h"


static int find_win(char *b, char s) {
    for (int i = 0; i < 9; i++) {
        if (b[i] != '.') continue;
        b[i] = s;
        char w = winner(b);
        b[i] = '.';
        if (w == s) return i;
    }
    return -1;
}

static int ai(char *b, char me) {
    char op = (me == 'X') ? 'O' : 'X';
    int m;
    if ((m = find_win(b, me)) >= 0) return m;   
    if ((m = find_win(b, op)) >= 0) return m;   
    if (b[4] == '.') return 4;                  
    int empty[9], n = 0;
    for (int i = 0; i < 9; i++) if (b[i] == '.') empty[n++] = i;
    return empty[rand() % n];
}

static void play_pve(void) {
    char board[10] = ".........";
    char player = 'X';                         

    for (;;) {
        show(board);
        int move;
        if (player == 'X') {
            move = ask_move(board, player);
        } else {
            move = ai(board, 'O');
            printf("ordinateur joue en %d\n", move);
        }
        board[move] = player;

        char w = winner(board);
        if (w != '-') {
            show(board);
            if (w == 'D') printf("Match nul\n");
            else          printf("%c a gagné\n", w);
            return;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

#endif