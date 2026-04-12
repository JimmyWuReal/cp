#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        const int m = a + b;
        if (m > n || (m > 0 && (a == 0 || b == 0))) {
            cout << "NO\n";
            continue;
        }

        vector<int> first(n), second(n);
        for (int i = 0; i < m; ++i) {
            first[i] = i + 1;
        }
        for (int i = 0; i < b; ++i) {
            second[i] = a + i + 1;
        }
        for (int i = 0; i < a; ++i) {
            second[b + i] = i + 1;
        }
        for (int i = m; i < n; ++i) {
            first[i] = i + 1;
            second[i] = i + 1;
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << ' ';
            }
            cout << first[i];
        }
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << ' ';
            }
            cout << second[i];
        }
        cout << '\n';
    }

    return 0;
}
