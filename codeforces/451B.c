#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("yes\n1 1");
        return 0;
    }

    int a[100000], b[2];
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    int f = 0, init, bef;
    init = bef = a[1] - a[0] > 0;

    for (int i = 2; i < n && f < 3; ++i) {
        int now = a[i] - a[i - 1] > 0;
        if (bef ^ now) {
            b[f++] = i - 1;
            bef = now;
        }
    }

    if (f > 2)
        printf("no");
    else if (f == 0)
        printf("yes\n1 %d", init ? 1 : n);
    else if (f == 1) {
        if (init && a[b[0] - 1] < a[n - 1])
            printf("yes\n%d %d", b[0] + 1, n);
        else if (!init && a[0] < a[b[0] + 1])
            printf("yes\n1 %d", b[0] + 1);
        else
            printf("no");
    } else if (init && f == 2 && a[b[0] - 1] < a[b[1]] && a[b[0]] < a[b[1] + 1])
        printf("yes\n%d %d", b[0] + 1, b[1] + 1);
    else
        printf("no");

    return 0;
}

/*

      v   v
1 2 3 6 5 4 7 8 9
 + + + - - + + +

        v
1 2 3 4 8 7 6 5
 + + + + - - -

      v
4 3 2 1 5 6 7 8

*/
