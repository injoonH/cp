#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>

int main() {
    int n;
    char s[26], v[26] = { 0, }, z[27] = { 0, };
    for (int i = 0; i < 26; ++i)
        s[i] = -1;
    scanf("%d", &n);
    while (n--) {
        char c[28] = { 0, };
        scanf("%27s", c);
        if (c[26]) {
            printf("NO");
            return 0;
        }
        for (int i = 0; c[i]; ++i) {
            int k = c[i] - 'a';
            if (v[k]) {
                if (!c[i + 1])
                    continue;
                int m = c[i + 1] - 'a';
                if (s[k] < 0)
                    s[k] = m;
                else if (s[k] != m) {
                    printf("NO");
                    return 0;
                }
            } else {
                v[k] = 1;
                if (c[i + 1])
                    s[k] = c[i + 1] - 'a';
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (!v[i]) continue;
        char y[26] = { 0, };
        for (int j = i; j >= 0; j = s[j]) {
            if (y[j]) {
                printf("NO");
                return 0;
            }
            y[j] = 1;
        }
    }

    char h[26];
    for (int i = 0; i < 26; ++i) h[i] = 1;
    for (int i = 0; i < 26; ++i) {
        if (!v[i]) {
            h[i] = 0;
            continue;
        }
        for (int j = s[i]; j >= 0; j = s[j]) {
            if (!h[j]) break;
            h[j] = 0;
        }
    }

    char x[26] = { 0, };
    for (int i = 0, q = 0; i < 26; ++i) {
        if (!h[i]) continue;
        for (int j = i; j >= 0; j = s[j]) {
            if (x[j]) {
                printf("NO");
                return 0;
            }
            z[q++] = 'a' + j;
            x[j] = 1;
        }
    }

    printf("%s", z);
    return 0;
}

/*

한 번씩만 등장해야 함.
아니면 그 substring을 이루는 char 중 하나가 그것이 될 것임.

즉, 주어진 substring을 모두 합치되, 중복되는 char가 존재한다면 그것은
한 번만 나와야 함.

1번 예시는 mail + ai = mail, mail + lru = mailru로 합쳐지기 때문에 괜찮음.
2번 예시는 애초에 preceq에 e가 두 번 등장하기도 하고 합칠 수 없기 때문에 실패.

만약 입력으로 길이 27 이상인 string이 들어오면 일단 NO.
비둘기집의 원리로 두 번 이상 등장하는 char 발생.

체인이 이렇게 두 개 생겼는데 lexicographical 빠르려면
그냥 빠른 알파벳으로 시작하는 chain부터 작성하면 됨

m - a - i - l - r - u
c - f

사이클이 발생하면 head가 공멸해서 사라짐.

ixgwdtlnfjvkzy
ehpuqmbao
cr

ab
bc
ca
gh

*/
