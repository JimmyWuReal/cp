#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n; 
    string s, p; cin>>s>>p; 

    for (int i=0; i<n; i++) {
        if (p[i]!='*' && p[i]!=s[i]) {
            cout<<"No"<<'\n'; 
            return 0; 
        }
    }

    cout<<"Yes"<<'\n'; 

    return 0;
}