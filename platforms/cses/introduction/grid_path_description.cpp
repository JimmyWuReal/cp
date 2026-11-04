
#include <bits/stdc++.h>
using namespace std;

string S;
bool vis[9][9];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

long long dfs(int r, int c, int s) {
    if (r == 7 && c == 1)
        return s == 48;

    if (s == 48) return 0;

    bool U = vis[r-1][c];
    bool D = vis[r+1][c];
    bool L = vis[r][c-1];
    bool R = vis[r][c+1];

    if (U && D && !L && !R) return 0;
    if (L && R && !U && !D) return 0;

    vis[r][c] = true;

    int forced = -1;

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (vis[nr][nc]) continue;

        bool target = (nr == 7 && nc == 1);
        if (target && s != 47) continue;

        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            cnt += !vis[nr + dr[j]][nc + dc[j]];
        }

        if (cnt == 0 && !(target && s == 47)) {
            vis[r][c] = false;
            return 0;
        }

        if (cnt == 1 && !target) {
            if (forced != -1) {
                vis[r][c] = false;
                return 0;
            }
            forced = k;
        }
    }

    long long ans = 0;

    for (int k = 0; k < 4; k++) {
        if (forced != -1 && forced != k)
            continue;

        if (S[s] != '?' && S[s] != dir[k])
            continue;

        int nr = r + dr[k];
        int nc = c + dc[k];

        if (!vis[nr][nc])
            ans += dfs(nr, nc, s + 1);
    }

    vis[r][c] = false;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;

    for (int i = 0; i < 9; i++) {
        vis[0][i] = true;
        vis[8][i] = true;
        vis[i][0] = true;
        vis[i][8] = true;
    }

    cout << dfs(1, 1, 0) << '\n';
}
