// Code written by Jimmy Wu (JingZe Wu) 
// AC during the contest 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long res = 0; 
    
    long long px = 0; 
    long long py = 0; 

    int n; 
    cin >> n; 

    while (n--) {
        long long a, b; 
        cin >> a >> b; 
        res += abs(a - px) + abs(b - py); 
        px = a; 
        py = b; 
    }

    res += abs(px) + abs(py); 

    cout << res << endl; 

    return 0;
}