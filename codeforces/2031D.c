#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t, n, mn, mni, a[500000], mx[500000], s[500000];
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, a);
        mx[0] = a[0];

        for (int i = 1; i < n; ++i) {
            scanf("%d", a + i);
            mx[i] = mx[i - 1] > a[i] ? mx[i - 1] : a[i];
        }

        s[n - 1] = mx[n - 1], mn = a[n - 1], mni = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] >= a[i + 1])
                s[i] = s[i + 1];
            else if (mx[i] > mn)
                s[i] = s[mni];
            else
                s[i] = mx[i];

            if (mn > a[i])
                mn = a[i], mni = i;
        }

        for (int i = 0; i < n; ++i)
            printf("%d ", s[i]);
        printf("\n");
    }

    return 0;
}

/*

Idea: Update backward

*/
