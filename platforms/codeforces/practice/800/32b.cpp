#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; 
    cin >> s; 

    string res; 

    int cnt = 0; 
    while (cnt < s.size()) {
        if (s[cnt] == '.') {
            res.push_back('0'); 
        } else {
            cnt++; 
            if (s[cnt] == '-') {
                res.push_back('2'); 
            } else {
                res.push_back('1'); 
            }
        }

        cnt++; 
    }

    cout << res << endl; 

    return 0;
}