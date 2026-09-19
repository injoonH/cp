#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <stdlib.h>

int f(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int t, n, a[200000];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            a[i] -= i;
        }
        qsort(a, n, sizeof(int), f);
        int p = 0;
        long long s = 0;
        for (int i = 1, k; i < n; ++i) {
            if (a[i] == a[i - 1])
                continue;
            k = i - p;
            s += (long long)k * (k - 1) / 2;
            p = i;
        }
        p = n - p;
        s += (long long)p * (p - 1) / 2;
        printf("%lld\n", s);
    }
    return 0;
}
