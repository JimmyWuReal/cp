#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> grid(N, vector<char>(M));
    vector<vector<bool>> seen(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (!seen[i][j] && grid[i][j] != '#') {
                queue<pair<int, int>> q;

                q.push({i, j});
                seen[i][j] = true;

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    if (r > 0 &&
                        grid[r - 1][c] != '#' &&
                        !seen[r - 1][c]) {

                        seen[r - 1][c] = true;
                        q.push({r - 1, c});
                    }

                    if (r < N - 1 &&
                        grid[r + 1][c] != '#' &&
                        !seen[r + 1][c]) {

                        seen[r + 1][c] = true;
                        q.push({r + 1, c});
                    }

                    if (c > 0 &&
                        grid[r][c - 1] != '#' &&
                        !seen[r][c - 1]) {

                        seen[r][c - 1] = true;
                        q.push({r, c - 1});
                    }

                    if (c < M - 1 &&
                        grid[r][c + 1] != '#' &&
                        !seen[r][c + 1]) {

                        seen[r][c + 1] = true;
                        q.push({r, c + 1});
                    }
                }

                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}