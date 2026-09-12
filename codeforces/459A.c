#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int a, b, p, q, d, e;
    scanf("%d %d %d %d", &a, &b, &p, &q);
    if (a == p) {
        a += b - q;
        printf("%d %d %d %d", a, b, a, q);
    } else if (b == q) {
        b += a - p;
        printf("%d %d %d %d", a, b, p, b);
    } else {
        d = a > p ? a - p : p - a;
        e = b > q ? b - q : q - b;
        if (d == e)
            printf("%d %d %d %d", a, q, p, b);
        else
            printf("-1");
    }
    return 0;
}
