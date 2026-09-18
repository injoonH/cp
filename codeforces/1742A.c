#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t, a, b, c, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        s = a;
        if (s < b) s = b;
        if (s < c) s = c;
        printf("%s\n", s << 1 == a + b + c ? "YES": "NO");
    }
    return 0;
}
