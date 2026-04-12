#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while(t--) {
        int n, k, a, b; 
        cin >> n >> k >> a >> b; 

        vector<ll> nums(n); 
        for (int i = 0; i < n; i++) cin >> nums[i]; 

        if (k > n) {
            cout << accumulate(nums.begin(), nums.end(), 0LL) << '\n';
            continue;
        }

        ll s = min(a, b);
        ll l = max(a, b);

        ll sum0 = 0;
        ll free_d = 0;

        vector<ll> need1(n), need0(n);

        for (int i = 0; i < n; ++i) {
            ll u = nums[i] % s;
            ll v = (nums[i] % l) % s;
            ll d = v - u;

            sum0 += u;
            free_d += min(0LL, d);
            need1[i] = max(0LL, d);
            need0[i] = max(0LL, -d);
        }

        ll w1 = 0;
        ll w0 = 0;
        for (int i = 0; i < k; ++i) {
            w1 += need1[i];
            w0 += need0[i];
        }

        ll best1 = w1;
        ll best0 = w0;

        for (int i = k; i < n; ++i) {
            w1 += need1[i] - need1[i - k];
            w0 += need0[i] - need0[i - k];
            best1 = min(best1, w1);
            best0 = min(best0, w0);
        }

        ll ans = sum0 + free_d + min(best1, best0);
        cout << ans << '\n';
    }


    return 0;
}
