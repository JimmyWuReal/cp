#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    long long ans = 0; 
    long long prev = 0; 
    
    for (int i = 0; i < n; i++) {
        int a; 
        cin >> a; 

        if (a > prev) ans += a - prev; 
        prev = a; 
    }

    cout << ans << endl; 

    return 0;
}