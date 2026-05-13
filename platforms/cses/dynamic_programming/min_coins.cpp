#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; 
    cin >> n >> x; 

    vector<int> nums(n); 
    for (int i = 0; i < n; i++) cin >> nums[i]; 

    vector<int> dp(x + 1, INT_MAX); 
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int c : nums) {
            if (i - c >= 0 && dp[i - c] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    if (dp[x] == INT_MAX) {
        cout << -1;
    } else {
        cout << dp[x];
    }

    return 0;
}