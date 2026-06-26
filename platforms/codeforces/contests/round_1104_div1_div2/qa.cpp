#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        int n; 
        cin >> n; 

        int m = INT_MAX; 
        int res = 0; 

        while (n--) {
            int x; 
            cin >> x; 

            m = min(x, m); 

            res += m; 
        }

        cout << res << endl; 
    }

    return 0;
}