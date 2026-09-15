#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int l = 0, u = 0;
    char s[101];
    scanf("%s", s);
    for (int i = 0; s[i]; ++i)
        if (s[i] > 'Z') ++l;
        else ++u;
    for (int i = 0; s[i]; ++i) {
        if ((s[i] > 'Z' && l >= u) || (s[i] < 'a' && u > l))
            continue;
        if (u > l) s[i] -= 32;
        else s[i] += 32;
    }
    printf("%s", s);
    return 0;
}
