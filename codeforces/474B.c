#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, a[100001] = { 0 };
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a[i] += a[i - 1];
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        int q, l = 1, r = n, h = 1;
        scanf("%d", &q);
        while (l <= r) {
            h = (l + r) >> 1;
            if (a[h] == q) break;
            if (a[h] > q) r = h - 1;
            else l = h + 1;
        }
        if (a[h] < q) ++h;
        printf("%d\n", h);
    }
    return 0;
}
