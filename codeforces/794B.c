#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <math.h>

int main() {
    int n, h;
    scanf("%d %d", &n, &h);
    for (int i = 1; i < n; ++i)
        printf("%.12f ", sqrt((double)i / n) * h);
    return 0;
}
