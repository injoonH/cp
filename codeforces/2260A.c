#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t, n, a, c, p;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        a = c = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p);
            if (!p) ++a;
            if (i == 0 || i == n - 1) c += p;
        }
        if (c == 0)
            printf("0\n");
        else if (a > 1)
            printf("%d\n", c);
        else
            printf("-1\n");
    }
    return 0;
}
