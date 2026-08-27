#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 
    
    vector<long long> num(n); 
    for (auto &x : num) cin >> x; 

    sort(num.begin(), num.end()); 

    long long ans = 0; 
    long long prefix = 0; 

    for (int i = 0; i < n; i++) {
        ans += num[i] * i - prefix; 
        prefix += num[i]; 
    }

    cout << ans << endl; 

    return 0;
}