#include <bits/stdc++.h>
using namespace std;

using pii=pair<int, int>; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 

    vector<pii> pt(N); 
    for (auto &[x, y] : pt) cin>>x>>y; 

    sort(pt.begin(), pt.end()); 
    pii ms=pt[0]; 
    pii me=pt[N-1]; 

    double sm=numeric_limits<double>::max(); 

    vector<pii> mk; 

    for (int i=1; i<N-1; i++) {
        pii cur=pt[i]; 
        if (cur.first<=ms.first || cur.second<=ms.second || cur.first>=me.first || cur.second>=me.second) continue;

        double m=(double)(cur.second-ms.second)/(cur.first-ms.first); 

        if (m==sm) {
            mk.push_back(cur); 
        } else if (m<sm) {
            sm=m; 
            mk={cur}; 
        }
    }

    if (mk.empty()) {
        cout<<"Not found\n"; 
        return 0; 
    }

    sort(mk.begin(), mk.end()); 

    cout<<ms.first<<' '<<ms.second<<'\n'; 
    for (auto &[x, y] : mk) cout<<x<<' '<<y<<'\n'; 
    cout<<me.first<<' '<<me.second<<'\n'; 

    return 0;
}