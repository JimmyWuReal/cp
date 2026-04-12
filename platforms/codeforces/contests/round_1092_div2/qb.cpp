#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    while(n--) {
        long long t, h, u; 
        cin >> t >> h >> u; 

        long long tu = min(t, u); 
        t -= tu; 
        u -= tu; 

        long long tht = 0; 
        long long th = 0; 
        
        if (t % 2 == 0) {
            tht = min(t / 2, h); 
            t -= 2 * tht; 
            h -= tht; 
            th = 0; 
        } else {
            tht = min(t / 2, h); 
            t -= 2 * tht; 
            h -= tht; 
            if (h >= 1) {
                t -= 1; 
                h -= 1; 
                th = 1; 
            } else {
                th = 0; 
            }
        }

        long long res = 0; 

        if (t > 0) {
            res = tu * 4 + tht * 7 + th * 5 + t * 2 + 1; 
        } else {
            res = tu * 4 + tht * 7 + th * 5 + u * 3 + h * 3; 
        }
        
        cout << res << endl; 
        // tu * 4
        // tht * 7 + th * 5 
        // all t * 2 + 1 
        // u * 3 
        // h * 3 
    }

    return 0;
}