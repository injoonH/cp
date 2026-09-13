#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int a[4];
    scanf("%d %d %d %d", a, a + 1, a + 2, a + 3);

    for (int i = 1; i < 4; i++) {
        int k = a[i], j = i - 1;
        for (; j >= 0 && a[j] > k; --j)
            a[j + 1] = a[j];
        a[j + 1] = k;
    }

    if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3])
        printf("TRIANGLE");
    else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3])
        printf("SEGMENT");
    else
        printf("IMPOSSIBLE");

    return 0;
}
