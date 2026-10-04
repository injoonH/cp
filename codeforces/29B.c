#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int l, d, v, g, r;
    scanf("%d %d %d %d %d", &l, &d, &v, &g, &r);
    g += r;
    int q = d / (v * g) + 1;
    double a;
    if (d < v * (q * g - r))
        a = (double)l / v;
    else
        a = (double)(l - d) / v + q * g;
    printf("%.8f", a);
    return 0;
}
