#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, p = 0, q = 0, r = 0, x = -1, y, u = -1, v, a[200000];
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            if (a[i] < 0) {
                ++p, y = i;
                if (x < 0) x = i;
            }
            else if (a[i]) {
                ++r, v = i;
                if (u < 0) u = i;
            }
            else ++q;
        }
        switch (r) {
            case 0:
                if (p < 2)
                    for (int i = 0; i < n; ++i)
                        printf("%d ", -a[i]);
                else
                    for (int i = 0; i < n; ++i)
                        printf("%d ", i == x || i == y);
                break;
            case 1:
                if (p < 1)
                    for (int i = 0; i < n; ++i)
                        printf("%d ", a[i] < 0 ? 0 : a[i]);
                else {
                    int g = x > u ? x - u : u - x,
                        h = y > u ? y - u : u - y,
                        t = g > h ? x : y;
                    for (int i = 0; i < n; ++i)
                        printf("%d ", i == u || i == t);
                }
                break;
            default:
                for (int i = 0; i < n; ++i)
                    printf("%d ", a[i] >= 0 ? a[i] : (i == x && x < u) || (i == y && v < y));
        }
        printf("\n");
    }
    return 0;
}

/*

... 1 0 0 0 0 0 0 0 1 ...

    |<----- k ----->|

1로 둘러싸인 연속된 0 개수가 최대가 되도록 해야 함

처음 -1과 마지막 -1 index 저장 (x, y)
처음 1과 마지막 1 index 저장 (u, v)

switch (1의 개수)
    case 0:
        if (-1 개수 < 2)
            print(전부 0)
        else
            print(가장 바깥 -1들을 1로 바꾸고 나머지 전부 0)
    case 1:
        if (-1 개수 < 1)
            print(전부 0)
        else
            print(해당 1과 가장 멀리 떨어진 -1만 1로 바꾸고 나머지 전부 0)
    else:
        -1 고려하지 않고 최댓값 계산
        if (가장 왼쪽과 오른쪽 1 바깥에 -1 존재)
            if (해당 -1을 1로 바꾸었을 때 최댓값 변화)

*/
