#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m; 

    vector<int> products(n); 
    for (auto &x : products) cin >> x; 

    int cnt = 0; 

    for (int i = 0; i < m; i++) {
        int s, f; 
        cin >> f >> s; 

        if (products[f - 1] >= s) {
            products[f - 1] -= s; 
            cnt++; 
        } 
    }

    cout << cnt << endl; 

    return 0;
}