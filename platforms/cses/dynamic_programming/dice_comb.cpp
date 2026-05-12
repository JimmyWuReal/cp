#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MOD = 1e9 + 7; 

    vector<long long> pos = {1, 2, 4, 8, 16, 32}; 

    int n; 
    cin >> n; 

    int cnt = 6; 

    while (cnt < n) {
        pos.push_back((pos[cnt - 1] + pos[cnt - 2] + pos[cnt - 3] + pos[cnt - 4] + pos[cnt - 5] + pos[cnt - 6]) % MOD); 
        cnt++; 
    }

    cout << pos[n - 1] << endl; 

    return 0;
}