#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        int n; 
        string s; 
        cin >> n >> s; 

        // no solution 
        if (s[0] == '0' || s.find("00") != string::npos) { 
            cout << -1 << endl; 
            continue; 
        }

        bool one = true; 

        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && ((i + 1) % 2 == 1)) {
                one = false; 
            }

            if (i > 0 && s[i] != '0' && s[i - 1] != '0' && s[i] != s[i - 1]) {
                one = false; 
            }
        }

        if (one) {
            cout << 1 << endl; 
            continue; 
        }

        // two 

        if (s.find("+--+") != string::npos || s.find("-++-") != string::npos) {
            cout << 3 << endl; 
            continue; 
        }

        cout << 2 << endl; 
    }

    return 0;
}