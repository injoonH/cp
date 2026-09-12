#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%s", n < 4 || n & 1 ? "NO" : "YES");
    return 0;
}
