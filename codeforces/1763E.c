#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int p, n, a[634];
    scanf("%d", &p);

    a[2] = 1;
    for (n = 2; n < 633 && a[n] <= p; ++n)
        a[n + 1] = a[n] + n;
    --n;

    int k[200001][2];
    k[0][0] = k[0][1] = 0;
    for (int w = 1; w <= p; ++w) {
        int mn = 1e9, mx = 0;
        for (int i = 2; i <= n && a[i] <= w; ++i) {
            int rm = w - a[i], cr = k[rm][0] + i;
            if (cr > mn)
                continue;
            if (cr < mn) {
                mn = cr;
                mx = k[rm][1] + k[rm][0] * i;
            } else {
                int t = k[rm][1] + k[rm][0] * i;
                if (mx < t)
                    mx = t;
            }
        }
        k[w][0] = mn;
        k[w][1] = mx;
    }

    printf("%d %d", k[p][0], k[p][1]);

    return 0;
}

/*

n(n-1)/2 <= p 만족하는 가장 큰 n 찾기

n   a[n]
2 - 1
3 - 3
4 - 6
5 - 10
6 - 15
7 - 21

노드 최소 개수를 만들어야 함.

p=12 - (8, 16)

12 = 10(5) + 1(2) + 1(2) -> 노드 개수 9
   =  6(4) + 6(4)        -> 노드 개수 8

중복 허용 knapsack인데 어떤 조합으로 물건을 뽑았는지 저장해야 함.
그런데 node 개수가 같은 조합이 여러 개일 수 있다면 그거 다 저장해야 함.

*/
