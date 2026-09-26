#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 
    while (T--) {
        int N; char C; cin>>N>>C; 
        string s; cin>>s; 

        int res=0; 

        for (int i=0; i<N/2; i++) {
            if (s[i]!=s[N-i-1]) {
                if (s[i]!=C) res++; 
                if (s[N-i-1]!=C) res++; 
            }
        }

        cout<<res<<'\n'; 
    }

    return 0;
}