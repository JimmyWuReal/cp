#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        long long a, b, x; 
        cin >> a >> b >> x; 

        vector<pair<long long, long long>> va, vb; 

        long long cur = a, cnt = 0; 

        while (true) {
            va.push_back({cur, cnt}); 
            if (cur == 0) break; 

            cur /= x;
            cnt++; 
        }

        cur = b; 
        cnt = 0; 

        while (true) {
            vb.push_back({cur, cnt}); 
            if (cur == 0) break; 

            cur /= x; 
            cnt++; 
        }

        long long ans = LLONG_MAX; 

        for (auto [x, ca] : va) {
            for (auto [y, cb] : vb) {
                ans = min(ans, ca + cb + llabs(x - y)); 
            }
        }

        cout << ans << endl; 
    }

    return 0;
}