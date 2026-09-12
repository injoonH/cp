#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, a, b, t, p, q;
    scanf("%d %d %d", &n, &a, &b);
    if (a < b) t = a, a = b, b = t;
    for (p = n / a; p >= 0; --p) {
        q = (n - a * p) / b;
        if (n == a * p + b * q) break;
    }
    if (p < 0) {
        printf("-1");
        return 0;
    }
    t = 1;
    while (p--) {
        for (int i = 1; i < a; ++i)
            printf("%d ", ++t);
        printf("%d ", ++t - a);
    }
    while (q--) {
        for (int i = 1; i < b; ++i)
            printf("%d ", ++t);
        printf("%d ", ++t - b);
    }
    return 0;
}
