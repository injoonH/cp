#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int p = 0;
    char c, s[101], t[201];
    scanf("%s", s);
    for (int i = 0; s[i]; ++i) {
        c = s[i] < 'a' ? s[i] + 32 : s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
            continue;
        t[p] = '.', t[p + 1] = c;
        p += 2;
    }
    t[p] = 0;
    printf("%s", t);
    return 0;
}
