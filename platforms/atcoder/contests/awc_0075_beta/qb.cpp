#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i];

    long long res = LLONG_MAX;

    for (int i = 0; i <= n - k; i++) {
        long long sum = prefix[i + k] - prefix[i];
        res = min(res, sum);
    }

    cout << res << '\n';

    return 0;
}