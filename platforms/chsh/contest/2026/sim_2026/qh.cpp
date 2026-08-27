#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    vector<long long> ans(n, 0);

    int p = 0;

    while (p < n) {
        int l = p;
        while (p < n && s[p] == 'R') p++;

        int mid = p - 1;

        int q = p;
        while (p < n && s[p] == 'L') p++;

        int a = mid - l + 1;
        int b = p - q;

        ans[mid] += (a + 1) / 2 + b / 2;
        ans[mid + 1] += a / 2 + (b + 1) / 2;
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}