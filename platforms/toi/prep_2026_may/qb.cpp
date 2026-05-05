#include <bits/stdc++.h>
using namespace std;

const int NEG = -1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P, R;
    cin >> N >> P >> R;

    vector<int> dp(P + 1, NEG);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;

        vector<pair<int, int>> items(M);
        for (int j = 0; j < M; j++) {
            int c, d;
            cin >> c >> d;
            items[j] = {c, d};
        }

        vector<vector<int>> local(R + 1, vector<int>(P + 1, NEG));

        for (int b = 0; b <= P; b++) {
            local[0][b] = dp[b];
        }

        for (auto [cost, delicious] : items) {
            for (int cnt = R - 1; cnt >= 0; cnt--) {
                for (int b = 0; b + cost <= P; b++) {
                    if (local[cnt][b] == NEG) continue;

                    local[cnt + 1][b + cost] = max(
                        local[cnt + 1][b + cost],
                        local[cnt][b] + delicious
                    );
                }
            }
        }

        vector<int> ndp(P + 1, NEG);
        for (int cnt = 0; cnt <= R; cnt++) {
            for (int b = 0; b <= P; b++) {
                ndp[b] = max(ndp[b], local[cnt][b]);
            }
        }

        dp.swap(ndp);
    }

    int ans = 0;
    for (int b = 0; b <= P; b++) {
        ans = max(ans, dp[b]);
    }

    cout << ans << '\n';

    return 0;
}