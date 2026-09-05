#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        int n; 
        cin >> n; 

        vector<long long> a(n);
        for (auto &x : a) cin >> x; 

        bool pos = true; 
        long long ans = 0; 

        for (int i = 0; i < n - 1; i++) {
            if (a[i] < 2 * a[i + 1]) {
                pos = false; 
                break; 
            }

            ans = max(ans, a[i] - 2 * a[i + 1]); 
        }

        if (!pos) {
            cout << -1 << endl; 
            continue; 
        }

        if (a[0] > 0) {
            ans = max(ans, 1LL); 
        }

        cout << ans << endl; 
    }

    return 0;
}