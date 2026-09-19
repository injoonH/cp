#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, m, a, b, q, r, t;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    if (a * m <= b)
        t = a * n;
    else
        q = n / m, r = n % m, t = b * q + (a * r < b ? a * r : b);
    printf("%d", t);
    return 0;
}
