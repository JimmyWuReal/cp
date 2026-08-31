#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long q, v; 
    cin >> q >> v; 

    priority_queue<long long> qu; 

    while (q--) {
        int x; 
        cin >> x; 

        if (x == 1) {
            long long t, w; 
            cin >> t >> w; 

            qu.push(w - t); 
        } else { 
            long long t; 
            cin >> t; 

            if (qu.empty()) {
                cout << -1 << endl; 
            } else {
                long long energy = qu.top() + t; 
                qu.pop(); 
                
                cout << min(v, energy) << endl; 
            }
        }
    }

    return 0;
}