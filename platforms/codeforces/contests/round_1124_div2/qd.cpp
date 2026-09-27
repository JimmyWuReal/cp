#include <bits/stdc++.h>
using namespace std;

bool good(int x) {
    return (__builtin_popcount(x)%2==0); 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N, Q; cin>>N>>Q; 

        vector<int> a(N); 

        int ans=0; 

        for (int i=0; i<N; i++) {
            cin>>a[i]; 
            if (good(a[i])) ans++; 
        }

        cout<<ans<<' '; 

        while (Q--) {
            int p, x; cin>>p>>x; 
            p--; 

            if (good(a[p])) ans--; 

            a[p]=x; 

            if (good(a[p])) ans++; 

            cout<<ans<<' '; 
        }
        
        cout<<'\n'; 
    }

    return 0;
}