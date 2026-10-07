#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

void solve() {
    int n, p = 0, not_printed, stack[200000];
    char s[200001], printed[200000] = {};
    scanf("%d %s", &n, s);
    not_printed = n;
    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case '1':
                stack[p++] = i;
                break;
            case '2':
                if (p == 0)
                    printed[i] = 1;
                else
                    printed[stack[--p]] = 1;
                --not_printed;
                break;
            default:
                printed[i] = 1;
                --not_printed;
        }
    }
    printf("%d\n", not_printed);
    if (not_printed)
        for (int i = 0; i < n; ++i)
            if (!printed[i])
                printf("%d ", i + 1);
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
