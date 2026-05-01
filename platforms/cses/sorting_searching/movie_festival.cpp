#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies.push_back({end, start});
    }

    sort(movies.begin(), movies.end());

    int t = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int end = movies[i].first;
        int start = movies[i].second;

        if (start >= t) {
            ans++;
            t = end;
        }
    }

    cout << ans << '\n';

    return 0;
}