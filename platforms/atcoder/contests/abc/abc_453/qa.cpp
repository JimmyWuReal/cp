#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    string s; 

    cin >> n; 
    cin >> s; 

    while(s[0] == 'o') {
        s.erase(s.begin()); 
    }

    cout << s; 

    return 0;
}