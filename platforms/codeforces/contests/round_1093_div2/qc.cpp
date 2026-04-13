#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll p, q;
        cin >> p >> q;


        // solve 


        ll s = p + 2 * q;
        ll x = 2 * s + 1;

        bool found = false;

        for (ll d = 1; d * d <= x; d++) {
            if (x % d != 0) continue;

            ll e = x / d;

            for (int rep = 0; rep < 2; rep++) {
                ll a = (rep == 0 ? d : e);
                ll b = (rep == 0 ? e : d);

                if ((a & 1) == 0 || (b & 1) == 0) continue;

                ll n = (a - 1) / 2;
                ll m = (b - 1) / 2;

                if (n <= 0 || m <= 0) continue;

                ll v = n * (m + 1);
                ll h = m * (n + 1);

                if (q <= min(v, h)) {
                    cout << n << " " << m << "\n";
                    found = true;
                    break;
                }
            }

            // solutiona lready found 
            if (found) break;
        }

        // not found 
        if (!found) cout << -1 << "\n";
    }

    return 0;
}