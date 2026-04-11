#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 4 == 0) {
        cout << "YES\n";

        vector<int> first, second;

        for (int i = 1; i <= n; i++) {
            if (i % 4 == 1 || i % 4 == 0) {
                first.push_back(i);
            } else {
                second.push_back(i);
            }
        }

        cout << first.size() << "\n";
        for (int x : first) cout << x << " ";
        cout << "\n";

        cout << second.size() << "\n";
        for (int x : second) cout << x << " ";
        cout << "\n";

    } else if (n % 4 == 3) {
        cout << "YES\n";

        vector<int> first, second;

        first.push_back(1);
        first.push_back(2);
        second.push_back(3);

        for (int i = 4; i <= n; i++) {
            if (i % 4 == 0 || i % 4 == 3) {
                first.push_back(i);
            } else {
                second.push_back(i);
            }
        }

        cout << first.size() << "\n";
        for (int x : first) cout << x << " ";
        cout << "\n";

        cout << second.size() << "\n";
        for (int x : second) cout << x << " ";
        cout << "\n";

    } else {
        cout << "NO\n";
    }

    return 0;
}