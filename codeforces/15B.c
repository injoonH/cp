#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t;
    long long n, m, a, b, c, p, q, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &a, &b, &p, &q);
        if (a > p) c = a, a = p, p = c;
        if (b > q) c = b, b = q, q = c;

        a += n - p;
        b += m - q;
        s = n * m - (a * b << 1);

        a <<= 1;
        b <<= 1;

        if (n < a && m < b)
            s += (a - n) * (b - m);

        printf("%lld\n", s);
    }
    return 0;
}
