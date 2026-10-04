#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    char f = 0, s[101];
    scanf("%s", s);
    for (int i = 0; s[i]; ++i)
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
            f = 1;
    printf("%s", f ? "YES" : "NO");
    return 0;
}
