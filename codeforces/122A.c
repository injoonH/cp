#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int f(int n) {
    for (int k; n; n /= 10) {
        k = n % 10;
        if (k != 4 && k != 7)
            return 0;
    }
    return 1;
}

int main() {
    int n, t = 0;
    scanf("%d", &n);
    for (int i = 1; i * i <= n && !t; ++i) {
        if (n % i != 0) continue;
        t = f(i) || f(n / i);
    }
    printf("%s", t ? "YES" : "NO");
    return 0;
}
