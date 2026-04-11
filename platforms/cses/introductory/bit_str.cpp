#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 
    
    long long cnt = 1;
    
    for (int i = 0; i < n; i++) {
        cnt *= 2; 
        cnt = cnt % MOD; 
    }

    cout << cnt; 

    return 0;
}