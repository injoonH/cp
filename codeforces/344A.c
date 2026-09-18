#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, s = 0;
    char c, t = 0;
    scanf("%d", &n);
    while (n--) {
        scanf(" %c%*c", &c);
        if (c != t)
            ++s, t = c;
    }
    printf("%d", s);
    return 0;
}
