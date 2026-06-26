#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c; 
    cin >> a >> b >> c; 

    int min = a; 
    if (b < min) min = b; 
    if (c < min) min = c; 

    a -= min; 
    b -= min; 
    c -= min; 

    if (a % 3 == 1 && b % 3 == 1 && c % 3 == 1 && min >= 2) {
        min -= 2; 
        a += 2; 
        b += 2; 
        c += 2; 
    } else if ((a % 3 == 2 ? 1 : 0) + (b % 3 == 2 ? 1 : 0) + (c % 3 == 2 ? 1 : 0) >= 2 && min >= 1) { 
        min--;
        a++; 
        b++; 
        c++; 
    }

    int res = min; 
    res += a / 3; 
    res += b / 3; 
    res += c / 3; 

    cout << res << endl; 

    return 0;
}