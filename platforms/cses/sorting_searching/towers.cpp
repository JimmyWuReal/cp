#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<int> towers;

    while (n--) {
        int x;
        cin >> x;

        auto pos = towers.upper_bound(x);

        if (pos != towers.end()) {
            towers.erase(pos);
        }

        towers.insert(x);
    }

    cout << towers.size() << '\n';

    return 0;
}