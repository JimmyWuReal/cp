#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N, M; cin>>N>>M; 

        if (N==1) {
            cout<<0<<'\n'; 
            continue;
        }

        int l=N/2;
        int t=N-l; 

        cout<<t<<'\n'; 

        for (int i=1; i<=t; i++) {
            cout<<i<<' '<<i+l-1<<'\n'; 
        }
    }

    return 0;
}