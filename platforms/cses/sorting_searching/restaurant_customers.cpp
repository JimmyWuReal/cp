#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        events.push_back({a, +1}); 
        events.push_back({b, -1}); 
    }

    sort(events.begin(), events.end());

    int curr = 0;
    int res = 0;

    for (auto [time, delta] : events) {
        curr += delta;
        res = max(res, curr);
    }

    cout << res << '\n';

    return 0;
}