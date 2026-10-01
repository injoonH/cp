#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a[200000];
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        for (int i = 0; i < n; ++i) {
            if (!a[i]) continue;
            if (a[i] < 0) a[i] = 1;
            break;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (!a[i]) continue;
            if (a[i] < 0) a[i] = 1;
            break;
        }
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i] < 0 ? 0 : a[i]);
        printf("\n");
    }
    return 0;
}

/*

... 1 0 0 0 0 0 0 0 1 ...

    |<----- k ----->|

1로 둘러싸인 연속된 0 개수가 최대가 되도록 해야 함

처음과 마지막 1 바깥쪽에 있는 -1에 대해 가장 바깥쪽 -1만 1로 변환

*/
