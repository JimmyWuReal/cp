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

        vector<int> a(n); 
        for (auto &x : a) cin >> x; 

        if (count(a.begin(), a.end(), 0) < 2) {
            cout << -1 << endl; 
        } else {
            int res = 2; 
            if (a[0] == 0) res--; 
            if (a[n - 1] == 0) res--; 

            cout << res << endl; 
        }
    }

    return 0;
}