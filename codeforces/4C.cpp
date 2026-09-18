#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    unordered_map<string, int> m;

    cin >> n;
    while (n--) {
        cin >> s;
        int k = m[s]++;
        if (k)
            cout << s << k << '\n';
        else
            cout << "OK\n";
    }

    return 0;
}
