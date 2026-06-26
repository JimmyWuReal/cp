#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    const int MAXT = 1e7 + 5;
    vector<long long> c(MAXT + 2, 0);

    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;

        int l = s;
        int r = t - d;

        if (l <= r) {
            c[l]++;
            c[r + 1]--;
        }
    }

    long long cur = 0;
    long long ans = 0;

    for (int x = 1; x <= MAXT; x++) {
        cur += c[x];
        ans += cur * (cur - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}