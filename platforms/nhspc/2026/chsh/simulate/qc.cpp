#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c;
    cin >> n >> c;

    vector<long long> s(n);
    for (auto &x : s) cin >> x;

    long long l = 0, r = 2000000001LL;

    while (r > l + 1) {
        long long mid = (l + r) / 2;

        __int128 cost = 0;

        for (long long x : s) {
            if (mid > x) {
                __int128 d = mid - x;
                cost += d * d;

                if (cost > c)
                    break;
            }
        }

        if (cost <= c)
            l = mid;
        else
            r = mid;
    }

    cout << l << '\n';
}