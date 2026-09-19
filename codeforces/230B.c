#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <math.h>

int p[1000001] = { 0, };

int f(int n) {
    if (p[n])
        return p[n] == 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p[n] = 2;
            return 0;
        }
    }
    p[n] = 1;
    return 1;
}

int main() {
    int n, b;
    long long a;
    scanf("%d", &n);
    while (n--) {
        scanf("%lld", &a);
        b = sqrt(a);
        if (a == 1 || (long long)b * b != a) {
            printf("NO\n");
            continue;
        }
        printf("%s\n", f(b) ? "YES" : "NO");
    }
    return 0;
}
