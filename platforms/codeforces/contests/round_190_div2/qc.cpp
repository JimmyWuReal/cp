#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];

        ll s = 0, rk = 0, rs = 0, cap = 0;
        // s: single number - number only appeared once 
        // rk: how many number isn't single
        // rs: total not single sum 

        for (ll x : c) {
            if (x == 1) {
                s++;
            } else {
                rk++;
                rs += x;
                cap += x / 2 - 1;
            }
        }

        ll ans = 0;

        if (rk == 0) {
            ans = 0;
        } else if (rk == 1) {
            ll cus = min(s, rs / 2);
            ans = rs + cus;
        } else {
            ll cus = min(s, cap);
            ans = rs + cus;
        }

        if (ans < 3) ans = 0;

        cout << ans << endl;
    }

    return 0;
}