#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <stdlib.h>

int f(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n, a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    qsort(a, n, sizeof(int), f);
    for (int p = 0, q = n - 1; p < q; ++p, --q)
        printf("%d %d ", a[p], a[q]);
    if (n & 1)
        printf("%d", a[n >> 1]);
    return 0;
}
