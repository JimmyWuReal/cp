#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; 
    cin >> s; 

    string res = ""; 

    for (char c : s) {
        if (isdigit(c)) {
            res.push_back(c); 
        }
    } 

    cout << res << endl; 

    return 0;
}