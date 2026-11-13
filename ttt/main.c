#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pvp.h"
#include "pve.h"

int main(void) {
    srand(time(NULL));
    int mode;
    printf("1) pvp\n2) pve\nMode : ");
    if (scanf("%d", &mode) != 1) return 1;

    if (mode == 1)      play_pvp();
    else if (mode == 2) play_pve();
    return 0;
}