#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int d, n, mn = 0, mx = 0, a[30][2];
    scanf("%d %d", &d, &n);
    for (int i = 0; i < d; ++i) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        mn += a[i][0];
        mx += a[i][1];
    }
    if (n < mn || mx < n) {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    n -= mn;
    for (int i = 0, k, s; i < d; ++i) {
        if (n) {
            s = a[i][1] - a[i][0];
            if (s <= n)
                k = a[i][1], n -= s;
            else
                k = a[i][0] + n, n = 0;
        } else
            k = a[i][0];
        printf("%d ", k);
    }
    return 0;
}
