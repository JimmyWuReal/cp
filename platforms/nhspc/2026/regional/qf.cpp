#include <bits/stdc++.h>
using namespace std;

using pdd=pair<double, double>; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double sunR, maxD; 
    int K; 
    cin>>sunR>>maxD>>K; 

    string s, t; cin>>s>>t; 

    vector<pdd> pt(8); 
    for (auto &[x, y] : pt) cin>>x>>y; 

    // 依照與太陽的距離排序
    sort(pt.begin(), pt.end(), [](pdd a, pdd b) {
        return a.first*a.first+a.second*a.second < b.first*b.first+b.second*b.second; 
    }); 

    vector<string> names={"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"}; 
    int st=find(names.begin(), names.end(), s)-names.begin(); 
    int ed=find(names.begin(), names.end(), t)-names.begin(); 

    // 合法的線段
    vector<vector<pair<int, double>>> adj(8); 

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (i==j) continue; 

            auto [ax, ay]=pt[i]; 
            auto [bx, by]=pt[j]; 

            double dx=bx-ax, dy=by-ay; 
            double d2=dx*dx+dy*dy; 

            if (d2>maxD*maxD) continue;

            double tt=-(ax*dx+ay*dy)/d2; 
            tt=max(0.0, min(1.0, tt)); 

            double px=ax+tt*dx, py=ay+tt*dy; 
            if (px*px+py*py<=sunR*sunR) continue; 

            adj[i].push_back({j, d2}); 
        }
    }

    // dijkstra {花費, {行星, 步數}}
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq; 

    pq.push({0, {st, 0}}); 

    while (!pq.empty()) {
        auto [d, cur]=pq.top(); pq.pop(); 
        auto [u, k]=cur; 

        if (u==ed) {
            cout<<fixed<<setprecision(2)<<d<<'\n'; 
            return 0; 
        }

        if (k==K) continue; 

        for (auto [v, w] : adj[u]) pq.push({d+w, {v, k+1}}); 
    }

    cout<<"UNREACHABLE\n"; 

    return 0;
}
