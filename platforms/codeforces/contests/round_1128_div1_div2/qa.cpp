#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 
    
    while (T--) {
        int N; cin>>N; 
        string s; cin>>s; 

        int f=0, l=0; 
        for (int i=0; i<N; i++) {
            if (s[i]=='1') {
                f=i; 
                break; 
            }
        }

        for (int i=N-1; i>=0; i--) {
            if (s[i]=='1') {
                l=i; 
                break; 
            }
        }

        if (count(s.begin(), s.end(), '1')==2) {
            cout<<1<<'\n'; 
        } else {
            cout<<l-f<<'\n';
        }
    }

    return 0;
}