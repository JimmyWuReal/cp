#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        long long mn=LLONG_MAX; 
        long long mx=LLONG_MIN; 

        for (int i=0; i<N; i++) {
            long long x; cin>>x; 

            mn=min(mn, x); 
            mx=max(mx, x); 
        }

        if (mn==mx) {
            cout<<mx<<'\n'; 
            continue;
        }

        long long diff=mn^mx; 

        int k=63-__builtin_clzll(diff); 

        long long ans=mx|((1LL<<k)-1); 

        cout<<ans<<'\n'; 
    }

    return 0;
}