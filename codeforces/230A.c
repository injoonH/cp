#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <stdlib.h>

typedef struct { int x, y; } D;

int f(const void* a, const void* b) {
    D *p = (D*)a, *q = (D*)b;
    if (p->x != q->x)
        return (p->x > q->x) - (p->x < q->x);
    return (p->y > q->y) - (p->y < q->y);
}

int main() {
    int s, n, t = 1;
    D a[1000];
    scanf("%d %d", &s, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &a[i].x, &a[i].y);
    qsort(a, n, sizeof(D), f);
    for (int i = 0; i < n && t; ++i) {
        if (s <= a[i].x) t = 0;
        else s += a[i].y;
    }
    printf("%s", t ? "YES" : "NO");
    return 0;
}
