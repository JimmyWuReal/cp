#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s; 
    cin >> n >> s; 

    vector<int> a(n); 
    for (auto &x : a) cin >> x;

    vector<int> dp(s + 1, 1e9); 

    dp[0] = 0; 

    for (int x : a) {
        for (int sum = s; sum >= x; sum--) {
            if (dp[sum - x] != 1e9) dp[sum] = min(dp[sum], dp[sum - x] + 1); 
        }
    }

    cout << (dp[s] == 1e9 ? -1 : dp[s]) << endl; 

    return 0;
}