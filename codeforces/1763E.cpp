#include <bits/stdc++.h>
using namespace std;

int f(vector<int> a, int sm) {
    int t = 0;
    for (int it : a)
        sm -= it, t += sm * it;
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int p, n, a[634];
    cin >> p;

    a[2] = 1;
    for (n = 2; n < 633 && a[n] <= p; ++n)
        a[n + 1] = a[n] + n;
    --n;

    pair<int, vector<vector<int>>> k[200001];
    k[0] = { 0, {{}} };
    for (int w = 1; w <= p; ++w) {
        int mn = 1e9;
        vector<vector<int>> cmb;

        for (int i = 2; i <= n && a[i] <= w; ++i) {
            int rm = w - a[i], cr = k[rm].first + i;
            if (cr > mn)
                continue;
            if (cr < mn) {
                mn = cr;
                cmb.clear();
            }
            for (auto& it : k[rm].second) {
                auto cp = it;
                cp.push_back(i);
                cmb.push_back(std::move(cp));
            }
        }

        for (auto& it : cmb)
            sort(it.begin(), it.end());
        sort(cmb.begin(), cmb.end());
        cmb.erase(unique(cmb.begin(), cmb.end()), cmb.end());

        k[w].first = mn;
        k[w].second = cmb;
    }

    int y = 0;
    for (auto& it : k[p].second) {
        int t = f(it, k[p].first);
        if (t > y)
            y = t;
    }

    cout << k[p].first << ' ' << y;

    return 0;
}

/*

n(n-1)/2 <= p 만족하는 가장 큰 n 찾기

n   a[n]
2 - 1
3 - 3
4 - 6
5 - 10
6 - 15
7 - 21

노드 최소 개수를 만들어야 함.

p=12 - (8, 16)

12 = 10(5) + 1(2) + 1(2) -> 노드 개수 9
   =  6(4) + 6(4)        -> 노드 개수 8

중복 허용 knapsack인데 어떤 조합으로 물건을 뽑았는지 저장해야 함.
그런데 node 개수가 같은 조합이 여러 개일 수 있다면 그거 다 저장해야 함.

*/
