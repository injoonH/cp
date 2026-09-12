#include <stdio.h>

int v[1000001] = { 0 };

int f(int n) {
    if (v[n])
        return v[n];
    for (int p = 2; p * p <= n; ++p)
        if (n % p == 0) {
            int q = f(n / p);
            v[n] = p > q ? p : q;
            return v[n];
        }
    v[n] = n;
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    int a = f(n);
    if (n == a) {
        printf("%d", n);
        return 0;
    }
    int m = 1e6;
    for (int p = n - a + 1; p <= n; ++p) {
        int b = f(p);
        if (b != p) b = p - b + 1;
        if (m > b) m = b;
    }
    printf("%d", m);
    return 0;
}
