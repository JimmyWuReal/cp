#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        long long N, K; cin>>N>>K; 
        string s; cin>>s; 

        long long z=0, o=0; 
        for (char c : s) {
            if (c=='1') o++; 
            else z++; 
        }

        if (z>o) {
            z+=min(o, K); 
            o=max(0LL, o-K); 
        } else {
            o+=min(z, K); 
            z=max(0LL, z-K); 
        }

        long long res=(o+1)*o/2+(z+1)*z/2+1; 

        cout<<res<<'\n'; 
    }

    return 0;
}