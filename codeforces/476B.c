#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0, d, h[11] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };
    char s[11], t[11];
    scanf("%s %s", s, t);
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '+') ++a;
        else --a;
        if (t[i] == '?') ++c;
        else if (t[i] == '+') ++b;
        else --b;
    }
    d = a > b ? a - b : b - a;
    if (a > b + c || a < b - c || (c - d) & 1)
        printf("0");
    else {
        d = (c - d) >> 1;
        d = h[c] / h[c - d] / h[d];
        printf("%.12f", (double)d / (1 << c));
    }
    return 0;
}
