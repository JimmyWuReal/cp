#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long kll;
    cin >> n >> kll;

    vector<i128> a(n + 1);
    i128 max_a = 0;

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        a[i] = x;
        max_a = max(max_a, a[i]);
    }

    i128 k = kll;

    auto f = [&](i128 x) -> bool {
        i128 need = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < x) {
                i128 diff = x - a[i];
                i128 t = (diff + i - 1) / i;

                need += t;
                if (need > k) return false;
            }
        }

        return need <= k;
    };

    i128 low = 0;
    i128 high = max_a + k * n + 1; 

    while (high - low > 1) {
        i128 mid = (low + high) / 2;

        if (f(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    auto pi = [](i128 x) {
        if (x == 0) {
            cout << 0;
            return;
        }

        string s;
        while (x > 0) {
            s.push_back(char('0' + x % 10));
            x /= 10;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    };

    pi(low);
    return 0;
}