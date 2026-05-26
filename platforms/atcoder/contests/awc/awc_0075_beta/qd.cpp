#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m; 
    cin >> n >> k >> m; 

    vector<long long> a(n); 
    for (auto &x : a) cin >> x; 

    sort(a.begin(), a.end()); 

    auto f = [&](long long d) -> bool {
        int b = 0; 
        int j = 0; 
        int i = 0; 

        while (i < n) {
            b++; 
            if (b > k) return false; 
            if (j < i) j = i; 
            while (j < n && a[j] - a[i] <= d) j++; 

            int can = min(m, j - i); 
            i += can; 
        }

        return true; 
    }; 

    long long low = -1; 
    long long high = a.back() - a.front(); 

    while (high - low > 1) {
        long long mid = low + (high - low) / 2; 
        if (f(mid)) {
            high = mid; 
        } else {
            low = mid; 
        }
    }

    cout << high << endl; 

    return 0;
}