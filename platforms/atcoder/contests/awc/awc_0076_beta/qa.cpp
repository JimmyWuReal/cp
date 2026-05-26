#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long s, p, r;
    cin >> s >> p >> r; 

    int m; 
    cin >> m; 

    while (m--) {
        long long e, v; 
        cin >> e >> v;

        if (e == 1) {
            s += v; 
        } else { 
            s -= v * p; 
        }
    }

    cout << s - r << endl;

    return 0;
}