#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    char s[20];
    scanf("%s", s);
    if (s[0] > '4' && s[0] != '9')
        s[0] = 0x69 - s[0];
    for (int i = 1; s[i]; ++i)
        if (s[i] > '4')
            s[i] = 0x69 - s[i];
    printf("%s", s);
    return 0;
}
