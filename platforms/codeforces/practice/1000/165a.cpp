#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 

    vector<pair<int, int>> p(N); 
    for (auto &[x, y] : p) cin>>x>>y; 

    int res=0; 

    for (int i=0; i<N; i++) {
        bool l=false, r=false, u=false, d=false; 

        for (int j=0; j<N; j++) {
            int x=p[i].first, y=p[i].second; 
            int x2=p[j].first, y2=p[j].second; 

            if (y==y2 && x2<x) l=true; 
            if (y==y2 && x2>x) r=true; 
            if (x==x2 && y2>y) u=true; 
            if (x==x2 && y2<y) d=true; 
        }

        if (l && r && u && d) res++; 
    }

    cout<<res<<'\n'; 

    return 0;
}