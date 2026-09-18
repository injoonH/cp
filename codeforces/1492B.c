#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t, n, p, a[100001], b[100000];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", b + i);
            a[b[i]] = i;
        }
        p = n;
        for (int i = n; i && p; --i) {
            int k = a[i];
            if (k < p) {
                for (int j = k; j < p; ++j)
                    printf("%d ", b[j]);
                p = k;
            }
        }
        printf("\n");
    }
    return 0;
}
