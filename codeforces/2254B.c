#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t, n, f, g;
    char s[200001];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %s", &n, s);
        f = g = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == s[i - 1])
                continue;
            if (s[i - 1] == s[i + 1]) {
                s[i] = s[i - 1];
                f = 1;
                break;
            }
            if (!g && s[i] != s[i + 1])
                g = 1;
        }
        int m = 1;
        for (int i = 1; i < n; ++i)
            if (s[i] != s[i - 1])
                ++m;
        printf("%d\n", f ? m : g ? m - 1 : m);
    }
    return 0;
}
