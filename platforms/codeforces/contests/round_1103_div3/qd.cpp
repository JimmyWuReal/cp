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

        vector<int> cnt(n + 2, 0);
        for (int i = 0; i < n; i++) {
            int x; 
            cin >> x; 
            cnt[x]++; 
        }

        vector<char> l(n + 2, 0); 

        int lw = 0; 
        bool ok = false; 

        for (int i = n; i >= 1; i--) {
            if (cnt[i] > 0) {
                bool h = lw > 0; 
                l[i] = (cnt[i] % 2 == 1 && !h); 
                if (!l[i]) ok = true; 
            }

            if (l[i]) lw++; 
            if (i + k <= n && l[i + k]) lw--; 
        }

        cout << (ok ? "YES" : "NO") << endl; 
    }

    return 0;
}