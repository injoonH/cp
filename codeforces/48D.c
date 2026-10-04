#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, t = 0, a[100000], b[100001] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        if (++b[a[i]] > t)
            t = b[a[i]];
    }
    for (int i = 2, m = b[1]; m < n; ++i) {
        if (b[i] > b[i - 1]) {
            printf("-1");
            return 0;
        }
        m += b[i];
    }
    printf("%d\n", t);
    for (int i = 0; i < n; ++i)
        printf("%d ", b[a[i]]--);
    return 0;
}
