#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, t; 
    cin >> n >> s >> t; 

    int b = s - t; 

    vector<long long> dp(b + 1, 0); 

    for (int i = 0; i < n; i++) {
        int c;
        long long v; 
        cin >> c >> v; 

        for (int x = b; x >= c; x--) {
            dp[x] = max(dp[x], dp[x - c] + v); 
        }
    }

    cout << dp[b] << endl; 

    return 0;
}