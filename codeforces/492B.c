#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <stdlib.h>

int f(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n, l, d, a[1000];
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    qsort(a, n, sizeof(int), f);
    d = (a[0] > l - a[n - 1] ? a[0] : l - a[n - 1]) << 1;
    for (int i = 1; i < n; ++i) {
        int k = a[i] - a[i - 1];
        if (d < k) d = k;
    }
    printf("%f", (double)d / 2);
    return 0;
}
