#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    int r, c;
    cin >> t >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    t = t % 360;

    if (t == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << grid[i][j] << " ";
            }
            cout << '\n';
        }
    }

    else if (t == 90) {
        // 90 degrees clockwise
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                cout << grid[r - j - 1][i] << " ";
            }
            cout << '\n';
        }
    }

    else if (t == 180) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << grid[r - i - 1][c - j - 1] << " ";
            }
            cout << '\n';
        }
    }

    else if (t == 270) {
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                cout << grid[j][c - i - 1] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}