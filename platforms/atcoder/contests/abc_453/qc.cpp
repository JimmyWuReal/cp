#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> l(n);
    for (int i = 0; i < n; i++) cin >> l[i];

    unordered_map<long long, int> dp, ndp;
    dp[1] = 0;

    for (int i = 0; i < n; i++) {
        long long len = 2 * l[i];
        ndp.clear();

        for (auto &[pos, cnt] : dp) {
            // Move away from 0
            long long p1 = pos + len;
            if (!ndp.count(p1) || ndp[p1] < cnt) {
                ndp[p1] = cnt;
            }

            long long p2 = llabs(pos - len);
            int add = (len > pos ? 1 : 0);
            if (!ndp.count(p2) || ndp[p2] < cnt + add) {
                ndp[p2] = cnt + add;
            }
        }

        dp.swap(ndp);
    }

    int ans = 0;
    for (auto &[pos, cnt] : dp) ans = max(ans, cnt);

    cout << ans << '\n';
    return 0;
}