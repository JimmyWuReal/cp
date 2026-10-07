#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, V; cin>>N>>V; 
    vector<int> w(N); 
    for (int &x : w) cin>>x; 

    int res=0; 

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            for (int k=j+1; k<N; k++) {
                if (i+j+k+3<=V) {
                    res=max(res, w[i]+w[j]+w[k]); 
                }
            }
        }
    }

    cout<<res<<'\n'; 

    return 0;
}