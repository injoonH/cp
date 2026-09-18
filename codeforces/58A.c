#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int p = 0;
    char s[101], t[] = "hello";
    scanf("%s", s);
    for (int i = 0; s[i] && p < 5; ++i)
        if (s[i] == t[p])
            ++p;
    printf("%s", p == 5 ? "YES" : "NO");
    return 0;
}
