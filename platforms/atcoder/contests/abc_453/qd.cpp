#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    pair<int, int> start = {-1, -1};
    pair<int, int> goal = {-1, -1};

    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') start = {i, j};
            if (grid[i][j] == 'G') goal = {i, j};
        }
    }

    constexpr int NONE = 4;
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    auto inside = [&](int r, int c) {
        return 0 <= r && r < h && 0 <= c && c < w;
    };

    vector visited(h, vector(w, array<bool, 5>{false, false, false, false, false}));
    struct PrevState {
        int r;
        int c;
        int dir;
    };
    vector parent(h, vector(w, array<PrevState, 5>{
        PrevState{-1, -1, -1},
        PrevState{-1, -1, -1},
        PrevState{-1, -1, -1},
        PrevState{-1, -1, -1},
        PrevState{-1, -1, -1}
    }));
    queue<tuple<int, int, int>> q;

    visited[start.first][start.second][NONE] = true;
    q.push({start.first, start.second, NONE});

    const char dir_char[4] = {'U', 'D', 'L', 'R'};

    while (!q.empty()) {
        auto [r, c, last_dir] = q.front();
        q.pop();

        if (make_pair(r, c) == goal) {
            string path;
            int cr = r;
            int cc = c;
            int cd = last_dir;
            while (!(cr == start.first && cc == start.second && cd == NONE)) {
                path.push_back(dir_char[cd]);
                auto prev = parent[cr][cc][cd];
                cr = prev.r;
                cc = prev.c;
                cd = prev.dir;
            }
            reverse(path.begin(), path.end());
            cout << "Yes\n";
            cout << path << '\n';
            return 0;
        }

        vector<int> next_dirs;
        char cell = grid[r][c];

        if (cell == '.' || cell == 'S' || cell == 'G') {
            next_dirs = {0, 1, 2, 3};
        } else if (cell == 'o') {
            if (last_dir != NONE) next_dirs = {last_dir};
        } else if (cell == 'x') {
            for (int dir = 0; dir < 4; dir++) {
                if (dir != last_dir) next_dirs.push_back(dir);
            }
        }

        for (int dir : next_dirs) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (!inside(nr, nc) || grid[nr][nc] == '#') continue;
            if (visited[nr][nc][dir]) continue;
            visited[nr][nc][dir] = true;
            parent[nr][nc][dir] = {r, c, last_dir};
            q.push({nr, nc, dir});
        }
    }

    cout << "No\n";
    return 0;
}
