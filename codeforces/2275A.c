#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t, x, y, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &x, &y, &r);
        printf("%d %d\n", x, y + r);
    }
    return 0;
}
