#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r, m; 
    cin >> n >> l >> r >> m; 

    int cnt = 0;

    while (n--) {
        int p, k; 
        cin >> p >> k; 

        if (l <= p && p <= r && k <= m) cnt++; 
    }

    cout << cnt << endl; 

    return 0;
}