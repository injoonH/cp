#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b, c;
        scanf("%d %d %d %d", &n, &a, &b, &c);
        if (a > b) a = b;
        if (a > c) a = c;
        printf("%d\n", n - a);
    }
    return 0;
}
