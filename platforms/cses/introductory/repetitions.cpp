#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; 
    cin >> s; 

    int m = 0; 
    int curr = 0; 
    char t = 'A'; 

    for (char c : s) {
        if (c == t) {
            curr++; 
            if (curr > m) m = curr; 
        } else {
            t = c; 
            curr = 1;  
        }
    }

    cout << m; 

    return 0;
}