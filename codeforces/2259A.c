#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, a = 0, b, d;
        char s[21];
        scanf("%d %d %s", &n, &k, s);
        for (int i = 0; i < n; ++i)
            a = (a << 1) + s[i] - '0';
        b = (1 << k) - 1;
        d = 0;
        for (int i = 0; i < n; i += k)
            if (((a >> i) & b) == b) ++d;
        printf("%d\n", d);
    }
    return 0;
}
