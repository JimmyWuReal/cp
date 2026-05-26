#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<vector<int>> map(n); 
    for (int i = 0; i < n; i++) {
        int l; 
        cin >> l; 

        for (int j = 0; j < l; j++) {
            int x; 
            cin >> x; 
            map[i].push_back(x); 
        }
    }

    int a, b;
    cin >> a >> b;

    cout << map[a - 1][b - 1] << endl; 

    return 0;
}