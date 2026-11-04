#include <bits/stdc++.h>
using namespace std;

using ll=long long; 
using pii=pair<long long, long long>; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 
    
    vector<vector<pii>> f(N); 

    for (int i=0; i<M; i++) {
        int s, e, c; cin>>s>>e>>c; 
        s--; e--; 
        f[s].push_back({e, c}); 
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq; 

    vector<ll> dp(N, LLONG_MAX); 
    dp[0]=0; 

    pq.push({dp[0], 0}); 

    set<int> visited; 

    while (!pq.empty()) {
        pii cur=pq.top();
        pq.pop(); 
        ll c=cur.first; 
        int pos=cur.second; 

        dp[pos]=min(dp[pos], c); 
        
        if (visited.count(pos)) continue;
        
        visited.insert(pos); 

        for (pii x : f[pos]) {
            if (!visited.count(x.first)) {
                pq.push({c+x.second, x.first}); 
            }
        }
    }

    for (int i=0; i<N; i++) {
        cout<<dp[i]<<' '; 
    }

    cout<<'\n'; 

    return 0;
}