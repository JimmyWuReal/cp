#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D; cin>>N>>D; 

    vector<int> p(N);
    for (int &x : p) cin>>x; 

    vector<int> res; 
    for (int i=0; i<N; i++) {
        bool pos=true; 
        for (int j=0; j<N; j++) {
            if (j==i) continue;
            if (abs(p[i]-p[j])<D) {
                pos=false; 
                break; 
            }
        }
        if (pos) res.push_back(i+1); 
    }

    cout<<res.size()<<'\n'; 
    for (int x : res) cout<<x<<' '; 

    return 0;
}