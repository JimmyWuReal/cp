#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x, y; 
        cin >> x >> y; 

        long long s = x + y; 
        long long a = 0; 
        bool smaller = false; 

        for (int i = 30; i >= 0; i--) {
            int sb = (s >> i) & 1; 
            int xb = (x >> i) & 1; 

            if (smaller) {
                if (sb) a |= (1LL << i); 
            } else {
                if (xb) {
                    if (sb) {
                        a |= (1LL << i); 
                    } else {
                        smaller = true; 
                    }
                }
            }
        }

        cout << s << " " << x - a << endl; 
    }

    return 0;
}