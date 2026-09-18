#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, t, p = 0, q = 1, m = 0, a[100001];
    scanf("%d %d", &n, &t);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a[i] += a[i - 1];
    }
    while (q <= n) {
        int x = a[q] - a[p];
        if (x > t) {
            ++p;
            continue;
        }
        if (q - p > m) m = q - p;
        ++q;
    }
    printf("%d", m);
    return 0;
}
