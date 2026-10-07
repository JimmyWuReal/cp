#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; 

    vector<vector<int>> grid; 

    while (getline(cin, s)) {
        if (s.empty()) break; 

        stringstream ss(s); 
        vector<int> nums; 
        
        int x; 
        while (ss >> x) {
            nums.push_back(x); 
        }

        grid.push_back(nums); 
    }

    int r = grid.size(); 
    int c = grid[0].size(); 

    vector<vector<int>> res(c, vector<int> (r, 0)); 

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[j][r - i - 1]= grid[i][j]; 
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << res[i][j] << " "; 
        }

        cout << '\n'; 
    }

    return 0;
}