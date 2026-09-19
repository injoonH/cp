#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t, n, k, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        s = 0;
        for (int i = 0, q; i < k;) {
            q = k - i;
            i += q - ((s + q) / n - s / n);
            s += q;
        }
        printf("%d\n", s);
    }
    return 0;
}
