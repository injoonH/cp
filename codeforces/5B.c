#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <string.h>

void f(char c, int n) {
    for (int i = 0; i < n; ++i) printf("%c", c);
}

int main() {
    int p = 0;
    size_t x = 0, n[1000], d = 0;
    char s[1001][1001];
    for (; fgets(s[p], 1001, stdin); ++p) {
        n[p] = strlen(s[p]) - 1;
        s[p][n[p]] = 0;
        if (x < n[p]) x = n[p];
    }
    f('*', x + 2);
    printf("\n");
    for (int i = 0; i < p; ++i) {
        size_t y = x - n[i];
        printf("*");
        f(' ', (y + d) >> 1);
        printf("%s", s[i]);
        f(' ', (y + !d) >> 1);
        printf("*\n");
        if (y & 1) d = !d;
    }
    f('*', x + 2);
    return 0;
}
