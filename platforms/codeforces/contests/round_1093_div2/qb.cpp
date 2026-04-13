#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        long long m;
        cin >> n >> m;

        // s

        vector<long long> blocked(n);
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            blocked[i] = (m - a) % m;
        }

        bool ok = true;
        long long r = 1;
        for (int i = 1; i < n; i++) {
            if (blocked[i] == blocked[i - 1]) {
                r++;
                if (r >= m) {
                    ok = false;
                    break;
                }
            } else {
                r = 1;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
