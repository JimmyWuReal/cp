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

        long long x; 
        cin >> x; 

        vector<long long> h(n); 
        for (auto &x : h) cin >> x; 

        sort(h.begin(), h.end()); 

        long long sum = 0; 

        bool found = false; 

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                sum += h[i]; 
            } else {
                if (h[i] * i - sum > x) {
                    long long water = h[i - 1] * i - sum; 
                    long long  left = x - water; 

                    cout << h[i - 1] + left / i << endl; 
                    found = true; 
                    break; 
                }

                sum += h[i]; 
            }
        }

        if (!found) {
            long long water = h[n - 1] * n - sum; 
            long long left = x - water; 

            long long space = left / n + h[n - 1];
            
            cout << space << endl; 
        }
    }

    return 0;
}