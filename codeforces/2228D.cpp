#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    pair<int, int> s[n];
    vector<int> ys;
    ys.reserve(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i].first >> s[i].second;
        ys.push_back(s[i].second);
    }

    sort(s, s + n);
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    vector<pair<int, int>> ln;
    ln.reserve(n);
    int cx = s[0].first, cmn = n, cmx = 0;
    for (int i = 0; i < n; ++i) {
        auto [x, y] = s[i];
        if (x == cx) {
            if (cmn > y) cmn = y;
            if (cmx < y) cmx = y;
        } else {
            ln.push_back({ cmn, cmx });
            cx = x, cmn = y, cmx = y;
        }
    }
    ln.push_back({ cmn, cmx });

    pair<int, int> fx[ln.size()];
    fx[ln.size() - 1] = { ln.back().first, ln.back().second };
    for (int i = ln.size() - 2; i > 0; --i) {
        fx[i].first = min(ln[i].first, fx[i + 1].first);
        fx[i].second = max(ln[i].second, fx[i + 1].second);
    }

    unsigned long long ans = 0;
    pair<int, int> l = { n, 0 };

    for (size_t i = 0; i < ln.size() - 1; ++i) {
        auto d = ln[i];

        if (l.first > d.first) l.first = d.first;
        if (l.second < d.second) l.second = d.second;

        auto r = fx[i + 1];

        int ymn = l.first > r.first ? l.first : r.first,
            ymx = l.second < r.second ? l.second : r.second;

        if (ymn >= ymx) continue;

        int imn = lower_bound(ys.begin(), ys.end(), ymn) - ys.begin(),
            imx = lower_bound(ys.begin(), ys.end(), ymx) - ys.begin();

        ans += imx - imn;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
