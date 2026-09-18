#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int m, s;
    scanf("%d %d", &m, &s);
    if (m == 1 && s == 0) {
        printf("0 0");
    } else if (s < 1 || s > m * 9) {
        printf("-1 -1");
    } else {
        int i = 0, q = s / 9, r = s % 9, t;
        char n[101], x[101];

        n[m] = x[m] = 0;
        if (!r)
            --q, r = 9;

        if (m == q + 1) {
            n[i++] = '0' + r;
            while (i < m)
                n[i++] = '9';
        } else {
            n[i++] = '1';
            t = m - q - 2;
            while (t--)
                n[i++] = '0';
            n[i++] = '0' + r - 1;
            while (i < m)
                n[i++] = '9';
        }

        for (i = 0; i < q; ++i)
            x[i] = '9';
        if (r)
            x[i++] = '0' + r;
        while (i < m)
            x[i++] = '0';

        printf("%s %s", n, x);
    }
    return 0;
}
