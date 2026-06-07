#include <bits/stdc++.h>
using namespace std;

bool s(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m; 
    cin >> n >> k >> m; 

    vector<pair<int, int>> gems; 

    for (int i = 0; i < n; i++) {
        int c, v; 
        cin >> c >> v; 

        gems.push_back({c, v}); 
    }

    sort(gems.begin(), gems.end(), s);

    set<int> color; 
    set<int> used; 

    int chosen = 0; 
    long long res = 0; 

    for (int i = 0; i < n; i++) {
        pair<int, int> g = gems[i]; 

        if (!color.count(g.first) && chosen < m) {
            res += g.second; 
            color.insert(g.first); 
            used.insert(i); 
            chosen++; 
        }
    }

    for (int i = 0; i < n; i++) {
        pair<int, int> g = gems[i]; 

        if (!used.count(i) && chosen < k) {
            res += g.second; 
            chosen++; 
        }
    }

    cout << res << endl; 

    return 0;
}