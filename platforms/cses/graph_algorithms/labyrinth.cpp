#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 

    vector<string> grid(N);
    pair<int,int> start;

    for (int r = 0; r < N; r++) {
        cin >> grid[r];
        for (int c = 0; c < M; c++) {
            if (grid[r][c] == 'A')
                start = {r, c};
        }
    }

    vector<vector<bool>> seen(N, vector<bool>(M));
    vector<vector<char>> parent(N, vector<char>(M));

    queue<pair<int,int>> q;
    q.push(start);
    seen[start.first][start.second] = true;

    int dr[] = {0, 0, -1, 1};
    int dc[] = {-1, 1, 0, 0};
    char dir[] = {'L', 'R', 'U', 'D'};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (grid[r][c] == 'B') {
            string path;

            while (make_pair(r, c) != start) {
                char d = parent[r][c];
                path += d;

                if (d == 'L') c++;
                else if (d == 'R') c--;
                else if (d == 'U') r++;
                else if (d == 'D') r--;
            }

            reverse(path.begin(), path.end());

            cout << "YES\n";
            cout << path.size() << '\n';
            cout << path << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (seen[nr][nc] || grid[nr][nc] == '#')
                continue;

            seen[nr][nc] = true;
            parent[nr][nc] = dir[i];
            q.push({nr, nc});
        }
    }

    cout << "NO\n";
}