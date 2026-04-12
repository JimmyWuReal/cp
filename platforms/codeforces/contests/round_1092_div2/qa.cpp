#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        // NOTE: k + 1 is the max level to go to 

        vector<int> a(k);
        for (int i = 0; i < k; ++i) cin >> a[i];

        vector<vector<int>> at_level(k);
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            --b;

            if (b < k) {
                at_level[b].push_back(i + 1);
            }
        }

        vector<int> ops;

        for (int lvl = k - 1; lvl >= 0; --lvl) {
            for (int id : at_level[lvl]) {
                for (int cur = lvl; cur < k; ++cur) {
                    ops.push_back(id);
                }
            }
        }

        cout << ops.size() << '\n';
        for (int i = 0; i < (int)ops.size(); ++i) {
            if (i) cout << ' ';
            cout << ops[i];
        }
        cout << '\n';
    }

    return 0;
}
