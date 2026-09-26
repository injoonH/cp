#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a = 0, b = 0, c = 0, m;
        while (n--) {
            scanf("%d", &m);
            if (m & 1) ++a;
            else if (m & 2) ++b;
            else ++c;
        }
        if (a < b) a = b;
        if (a < c) a = c;
        printf("%d\n", a);
    }
    return 0;
}

/*

홀수는 모두 1에서 멈춤
4n + 2와 4n은 만날 수 없음

*/
