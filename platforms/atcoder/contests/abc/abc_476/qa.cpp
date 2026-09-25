#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;
    if (s[s.size()-1] != 'e') {
        s.push_back('e'); 
    }

    s.push_back('r'); 

    cout<<s<<'\n'; 

    return 0;
}