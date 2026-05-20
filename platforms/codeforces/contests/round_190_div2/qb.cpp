#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();

        vector<int> preffix(n + 1, 0);
        vector<int> suffix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            preffix[i + 1] = preffix[i] + (s[i] == '2');
        }

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (s[i] == '1' || s[i] == '3');
        }

        int best = 0;

        for (int split = 0; split <= n; split++) {
            best = max(best, preffix[split] + suffix[split]);
        }

        cout << n - best << endl;
    }

    return 0;
}