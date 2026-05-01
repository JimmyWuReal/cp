#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> len(n);
    for (int i = 0; i < n; i++) cin >> len[i];

    sort(len.begin(), len.end());

    long long median = len[n / 2];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += llabs(len[i] - median);
    }

    cout << ans << '\n';

    return 0;
}