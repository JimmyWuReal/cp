#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while(t--) {
        long long a, b, n; 
        cin >> n >> a >> b; 

        long long g, i; 
        g = n / 3; 
        i = n % 3; 

        if (a * 3 < b) {
            cout << a * n << endl; 
        } else {
            long long c = min((a * i), b); 
            cout << c + b * g << endl; 
        }
    }

    return 0;
}