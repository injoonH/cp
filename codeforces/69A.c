#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, a, b, c, x, y, z;
    scanf("%d", &n);
    for (a = b = c = 0; n--; a += x, b += y, c += z)
        scanf("%d %d %d", &x, &y, &z);
    printf("%s", a || b || c ? "NO" : "YES");
    return 0;
}
