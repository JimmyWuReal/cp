#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<vector<int>> grid = {{0}}; 
    vector<unordered_set<int>> v = {{0}}; 
    vector<unordered_set<int>> h = {{0}};  

    if (n == 1) {
        cout << "0"; 
        return 0; 
    }

    int s = 0; 

    for (int i = 1; i < n; i++) {
        s++; 

        h.push_back({}); 

        for (int j = 0; j < s; j++) {
            int m = 0; 
            while (v[j].count(m) || h[s].count(m)) m++; 
            grid[j].push_back(m); 
            v[j].insert(m); 
            h[s].insert(m); 
        }

        v.push_back({}); 
        grid.push_back({}); 
        
        for (int j = 0; j < s + 1; j++) {
            int m = 0; 
            while (h[j].count(m) || v[s].count(m)) m++; 
            grid[s].push_back(m); 
            h[j].insert(m); 
            v[s].insert(m); 
        }
    }

    for (vector<int> g : grid) {
        for (int x : g) {
            cout << x << " "; 
        } 
        cout << endl; 
    }

    return 0;
}