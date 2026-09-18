#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, m, a;
    scanf("%d %d %d", &n, &m, &a);
    n = (n + a - 1) / a;
    m = (m + a - 1) / a;
    printf("%lld", (long long)n * m);
    return 0;
}
