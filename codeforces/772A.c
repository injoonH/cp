#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <stdlib.h>

typedef struct { int a, b; } D;

int f(const void* x, const void* y) {
    D *p = (D*)x, *q = (D*)y;
    long long d = (long long)p->b * q->a - (long long)q->b * p->a;
    return d > 0 ? 1 : d ? -1 : p->a - q->a;
}

int main() {
    int n, p;
    long long m = 0;
    D d[100000];

    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &d[i].a, &d[i].b);
        m += d[i].a;
    }

    if (m <= p) {
        printf("-1");
        return 0;
    }

    qsort(d, n, sizeof(D), f);

    long long a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if ((b + d[i].b) * d[i].a < (a + d[i].a - p) * d[i].b)
            break;
        a += d[i].a;
        b += d[i].b;
    }

    printf("%.10f", (double)b / (a - p));
    return 0;
}
