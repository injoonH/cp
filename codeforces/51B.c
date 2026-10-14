#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <stdlib.h>

int f(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n = 0, p = 0, m = 0, stack[600], ans[600];
    char s[2500];
    for (int c; (c = getchar()) != EOF;)
        switch (c) {
            case 'a': case 'd': case 'r': case '/':
                s[n++] = (char)c;
        }
    for (int i = 0; i < n; ++i)
        switch (s[i]) {
            case 'a':
                if (i && s[i - 1] == '/')
                    ans[m++] = stack[p--];
                else
                    stack[++p] = 0;
                break;
            case 'd':
                if (s[i - 1] == '/')
                    ++stack[p];
        }
    qsort(ans, m, sizeof(int), f);
    for (int i = 0; i < m; ++i)
        printf("%d ", ans[i]);
    return 0;
}
