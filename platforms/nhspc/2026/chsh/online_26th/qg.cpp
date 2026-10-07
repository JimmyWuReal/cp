#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        int n;
        long long h; 
        cin >> n >> h; 

        vector<long long> a(n);
        for (auto &x : a) cin >> x; 

        long long l = 1, r = h; 

        while (l < r) {
            long long mid = l + (r - l) / 2; 

            long long damage = mid; 

            for (int i = 0; i < n - 1; i++) {
                damage += min(mid, a[i + 1] - a[i]); 

                if (damage >= h) break; 
            }

            if (damage >= h) {
                r = mid; 
            } else {
                l = mid + 1; 
            }
        }        

        cout << l << endl; 
    }

    return 0;
}