#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        ll x, y, k; 
        cin >> x >> y >> k; 

        ll d = y - x; 
        ll cnt = 0; 
        if (d >= x) cnt = d - x + 1; 

        cnt = min(cnt, k); 

        ll ans = 0; 
        for (ll i = 0; i < cnt; i++) ans += d % (x + i); 

        ans += (k - cnt) * d; 

        cout << ans << endl; 
    }

    return 0;
}