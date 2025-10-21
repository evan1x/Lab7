/* Midterm Bonus
Evan Nickason 1309237 
2025-10-21 */

#include <stdio.h>

int main(void) {
    int N;
    printf("please enter N: ");
    if (scanf("%d", &N) != 1 || N <= 0) return 0;

    for (int i = 0; i < N; i++) printf("-");
    printf("\n");

    for (int r = 2; r <= N; r++) {
        int used = 0;

        for (int i = 0; i < r - 1 && used < N; i++) {
            printf("*");
            used++;
        }

        int bang_len = r - 1;
        int underscore_turn = 1;

        while (used < N) {
            if (underscore_turn) {
                if (used < N) { printf("_"); used++; }
            } else {
                int len = bang_len;
                if (used + len > N) len = N - used;
                for (int i = 0; i < len; i++) printf("!");
                used += len;
            }
            underscore_turn = !underscore_turn;
        }
        printf("\n");
    }
    return 0;
}
