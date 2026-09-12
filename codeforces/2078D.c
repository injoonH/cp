#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b;
        unsigned long long l = 1, r = 1, t = 0;
        char c, d;
        scanf("%d", &n);
        while (n--) {
            scanf(" %c %d %c %d", &c, &a, &d, &b);
            if (c != d) {
                if (c == 'x') {
                    l += t;
                    t = l * --a + b;
                } else {
                    r += t;
                    t = r * --b + a;
                }
            } else if (c == 'x') {
                if (a == b)
                    t += (l + r + t) * (a - 1);
                else {
                    if (a > b)
                        l += t;
                    else
                        r += t;
                    t = l * --a + r * --b;
                }
            } else
                t += a + b;
        }
        printf("%llu\n", l + r + t);
    }
    return 0;
}
