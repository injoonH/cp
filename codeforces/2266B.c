#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

#define f(a) (a > 0 ? a : -(a))

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        c = f(a + c - b), b = f(a - b);
        printf("%lld\n", b > c ? b : c);
    }
    return 0;
}
