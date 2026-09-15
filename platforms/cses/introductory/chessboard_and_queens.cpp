#include <bits/stdc++.h>
using namespace std;

int dp(const vector<pair<int, int>>& reserved, vector<int> placed) {
    int row = placed.size();

    if (row == 8)
        return 1;

    int cnt = 0;

    for (int col = 0; col < 8; col++) {
        if (find(reserved.begin(), reserved.end(), make_pair(row, col))
            != reserved.end())
            continue;

        if (find(placed.begin(), placed.end(), col) != placed.end())
            continue;

        bool valid = true;

        for (int prevRow = 0; prevRow < placed.size(); prevRow++) {
            if (abs(row - prevRow) == abs(col - placed[prevRow])) {
                valid = false;
                break;
            }
        }

        if (valid) {
            placed.push_back(col);
            cnt += dp(reserved, placed);
            placed.pop_back();
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> reserved;

    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 8; j++) {
            if (s[j] == '*')
                reserved.push_back({i, j});
        }
    }

    cout << dp(reserved, {}) << '\n';
}