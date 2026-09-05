#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x; 
    cin >> x; 

    int q = x / 25; 
    int r = x % 25; 

    string res; 

    res += string(q, 'A'); 

    if (r > 0) {
        res += string (25 - r, 'C'); 
        res += 'A'; 
        res += string(r, 'C'); 
        res += string(24 - q - 1, 'A'); 
    } else {
        res += string(25, 'C'); 
        res += string(24 - q, 'A'); 
    }

    string ans; 

    for (int i = 0; i < res.size(); i++) {
        if (i > 0) ans += 'R'; 
        ans += res[i]; 
    }

    cout << ans << endl; 

    return 0;
}

