#include <bits/stdc++.h>
using namespace std;

bool s(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<pair<int, int>> pos(n); 
    for (auto &p : pos) cin >> p.first >> p.second; 

    sort(pos.begin(), pos.end(), s); 

    int min = INT_MAX; 
    int res = 0; 

    for (pair<int, int> p : pos) {
        if (p.second < min) {
            res++; 
            min = p.second; 
        } 
    }

    cout << res << endl; 

    return 0;
}