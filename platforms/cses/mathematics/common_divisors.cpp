#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    vector<int> m(1e6+1, 0); 
    int mx=0; 
    for (int i=0; i<N; i++) {
        int x; cin>>x; 
        m[x]++; 
        mx=max(x,mx); 
    }

    int res=1; 

    for (int i=2; i<=mx; i++) {
        int cnt=0; 
        int t=0; 
        for (int t=i; t<=mx; t+=i) {
            cnt+=m[t]; 
            if (cnt>=2) {
                res=i; 
                break; 
            }
        }
    }

    cout<<res<<'\n'; 

    return 0; 
}