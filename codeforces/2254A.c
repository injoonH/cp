#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c, d;
        scanf("%d %d %d", &a, &b, &c);
        if (a > b) d = a, a = b, b = d;
        if (a > c) d = a, a = c, c = d;
        if (b > c) d = b, b = c, c = d;
        if (a == b || b == c)
            printf("0\n");
        else {
            c -= b, b -= a;
            printf("%d\n", b < c ? b : c);
        }
    }
    return 0;
}
