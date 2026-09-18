#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        if (i & 1) printf("I love ");
        else printf("I hate ");
        if (i < n - 1) printf("that ");
    }
    printf("it");
    return 0;
}
