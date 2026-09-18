#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", (n + 4) / 5);
    return 0;
}
