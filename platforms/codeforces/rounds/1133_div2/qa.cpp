#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N, K; cin>>N>>K; 

        int oa=0, ob=0; 
        
        for (int i=0; i<N; i++) {
            int x; cin>>x; 
            if (x%2!=0) oa++; 
        }

        for (int i=0; i<N; i++) {
            int x; cin>>x; 
            if (x%2!=0) ob++; 
        }

        if (K%2==0) {
            cout<<(oa>=ob ? "YES" : "NO")<<'\n';
        } else {
            cout<<(oa<=ob ? "YES" : "NO")<<'\n';
        }
    }

    return 0;
}