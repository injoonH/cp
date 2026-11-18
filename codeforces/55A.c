#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, p = 0, s = 0, f = 0;
    char a[1000] = { 0, };
    scanf("%d", &n);
    for (int i = 0, m = n << 1; i < m; p = (p + ++i) % n) {
        if (a[p]) continue;
        a[p] = 1;
        if (++s == n) {
            f = 1;
            break;
        }
    }
    printf("%s", f ? "YES" : "NO");
    return 0;
}
