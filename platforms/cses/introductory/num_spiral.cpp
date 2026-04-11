#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    for (int i = 0; i < n; i++) {
        long long x, y; 
        cin >> y >> x; 

        long long m = max(x, y); 

        if (max(x, y) % 2 == 0) {
            if (x == y) {
                cout << m * (m - 1) + 1; 
            } else if (x > y) {
                cout << m * (m - 1) + 1 - (m - y); 
            } else {
                cout << m * (m - 1) + 1 + (m - x); 
            }
        } else {
            if (x == y) {
                cout << m * (m - 1) + 1; 
            } else if (x > y) {
                cout << m * (m - 1) + 1 + (m - y); 
            } else {
                cout << m * (m - 1) + 1 - (m - x); 
            }
        }

        cout << endl; 
    }

    return 0;
}