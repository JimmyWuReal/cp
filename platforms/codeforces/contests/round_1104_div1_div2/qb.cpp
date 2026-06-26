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

        vector<long long> a(n), b(n); 
        for (auto &x : a) cin >> x; 
        for (auto &x : b) cin >> x; 

        vector<int> p(n, -1); 
        vector<bool> used(n, false); 

        int can = true; 

        for (int i = 0; i < n; i++) {
            int need = lower_bound(b.begin(), b.end(), a[i]) - b.begin(); 

            if (need == n) {
                can = false; 
                break; 
            }

            int chosen = -1; 

            for (int j = need; j < n; j++) { 
                if (!used[j]) {
                    chosen = j; 
                    break; 
                }
            }

            if (chosen == -1) { 
                can = false; 
                break; 
            }

            used[chosen] = true; 
            p[i] = chosen; 
        }

        if (!can) {
            cout << -1 << endl; 
            continue;
        } 

        long long ans = 0; 

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (p[i] > p[j]) ans++; 
            }
        }

        cout << ans << endl;
    }

    return 0;
}