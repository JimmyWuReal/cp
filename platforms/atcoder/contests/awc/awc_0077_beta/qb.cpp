#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; 
    cin >> n >> m >> k; 

    vector<long long> a(n); 
    for (auto &x : a) cin >> x; 

    vector<long long> prefix(n + 1); 
    prefix[0] = 0; 

    vector<long long> res;
    
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i]; 

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            if (j - i <= k) {
                res.push_back(prefix[j] - prefix[i]); 
            }
        }
    }

    sort(res.begin(), res.end(), greater<long long>()); 

    long long ans = 0; 
    int cnt = 0; 

    while (m--) {
        ans += res[cnt]; 
        cnt++; 
    }

    cout << ans << endl; 

    return 0;
}