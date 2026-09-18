#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, a, b, c, x;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    if ((a ^ b) & 1)
        printf("%d", (a ^ c) & 1 ? 1 : 2);
    else if ((a ^ c) & 1)
        printf("3");
    else
        for (int i = 4; i <= n; ++i) {
            scanf("%d", &x);
            if ((a ^ x) & 1)
                printf("%d", i);
        }
    return 0;
}
