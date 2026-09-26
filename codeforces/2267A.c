#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t, n, m;
    char c, s[101];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %c %s", &n, &c, s);
        m = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (s[i] == s[j]) continue;
            if (s[i] == c || s[j] == c) ++m;
            else m += 2;
        }
        printf("%d\n", m);
    }
    return 0;
}
