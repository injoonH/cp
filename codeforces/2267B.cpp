#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    map<int, int> a;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> m;
            a[m]++;
        }
        while (n) {
            for (auto iter = a.rbegin(); iter != a.rend(); ++iter) {
                if (iter->second) {
                    cout << iter->first << ' ';
                    iter->second--;
                    --n;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
