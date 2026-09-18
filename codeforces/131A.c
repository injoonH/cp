#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, m;
    char s[101];
    scanf("%s", s);
    for (n = m = 0; s[n]; ++n)
        if (s[n] < 'a') ++m;
    if (n == m || (n == m + 1 && s[0] > 'Z'))
        for (int i = 0; s[i]; ++i)
            s[i] += s[i] < 'a' ? 32 : -32;
    printf("%s", s);
    return 0;
}
