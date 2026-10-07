#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N, X; cin>>N>>X; 
        int sum=0; 
        bool all=true; 
        bool seen=false; 
        for (int i=0; i<N; i++) {
            int x; cin>>x; 
            sum+=x; 
            if (all && x!=X) all=false; 
            if (x==X) seen=true; 
        }

        if (all) {
            cout<<0<<'\n'; 
        } else if (sum==N*X || seen) {
            cout<<1<<'\n'; 
        } else {
            cout<<2<<'\n'; 
        }
    }

    return 0; 
}