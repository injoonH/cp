#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n, t = 0;
    char s[100001];
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; ++i)
        t += s[i] == 'A' ? 1 : -1;
    printf("%s", t ? t > 0 ? "Anton" : "Danik" : "Friendship");
    return 0;
}
