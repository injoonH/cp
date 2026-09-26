#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t, n, a[101];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        int p = 1, q = n, f = 1;
        while (p < q) {
            while (p <= n && a[p] == p) ++p;
            while (q >= 1 && a[q] == q) --q;
            if (p < q && (a[p] != q || a[q] != p)) {
                f = 0;
                break;
            }
            ++p, --q;
        }
        printf("%s\n", f ? "YES" : "NO");
    }
    return 0;
}
