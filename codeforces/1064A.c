#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int a, b, c, m;
    scanf("%d %d %d", &a, &b, &c);
    m = a;
    if (m < b) m = b;
    if (m < c) m = c;
    m <<= 1, a += b + c;
    printf("%d", m < a ? 0 : m - a + 1);

    return 0;
}
