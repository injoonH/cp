#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, a, mnv = 1e9 + 1, mxv = 0;
    long long mnc, mxc;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (mnv > a) mnv = a, mnc = 1;
        else if (mnv == a) ++mnc;
        if (mxv < a) mxv = a, mxc = 1;
        else if (mxv == a) ++mxc;
    }
    long long t = mxv == mnv ? (mxc * (mxc - 1)) >> 1 : mxc * mnc;
    printf("%d %lld", mxv - mnv, t);
    return 0;
}
