#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m; 

    vector<vector<char>> grid(n, vector<char>(m)); 
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j]; 

    vector<vector<char>> res(n, vector<char>(m)); 

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        vector<char> poss = {'A', 'B', 'C', 'D'}; 

        if (i != 0) poss.erase(remove(poss.begin(), poss.end(), res[i - 1][j]), poss.end()); 
        if (j != 0) poss.erase(remove(poss.begin(), poss.end(), res[i][j - 1]), poss.end()); 
        poss.erase(remove(poss.begin(), poss.end(), grid[i][j]), poss.end()); 

        res[i][j] = poss[0]; 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j]; 
        }
        cout << endl; 
    }

    return 0;
}