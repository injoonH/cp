#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y;
        long long k, a = 0;
        scanf("%d %d %lld", &x, &y, &k);
        for (; k-- && y >= x << 1; ++x, ++y)
            a += y % x;
        a += ++k * (y - x);
        printf("%lld\n", a);
    }
    return 0;
}

/*

(y % x) + (y+1 % x+1) + (y+2 % x+2) + ...

y + d = 2(x + d)
d = y - 2x

*/
