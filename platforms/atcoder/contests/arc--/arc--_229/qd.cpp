#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        int k; 
        cin >> k;

        vector<long long> a(k + 1); 

        long long m = LONG_LONG_MAX; 

        for (auto &x : a) {
            cin >> x; 
            m = min(m, x); 
        }

        long long ex = 0; 
        for (long long x : a) {
            ex += x - m; 
        }

        if (m % k == 0 && ex < k) {
            cout << "Bob" << endl; 
        } else {
            cout << "Alice" << endl; 
        }
    }

    return 0;
}