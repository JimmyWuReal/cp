#include <bits/stdc++.h>
using namespace std;

using ll=long long; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q; cin>>N>>M>>Q; 

    vector<vector<ll>> dis(N, vector<ll>(N, LLONG_MAX)); 

    for (int i=0; i<N; i++) dis[i][i]=0; 

    for (int i=0; i<M; i++) {
        ll a, b, c; cin>>a>>b>>c;
        a--; b--;  

        dis[a][b]=min(dis[a][b], c); 
        dis[b][a]=min(dis[b][a], c); 
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                if (dis[i][j]!=LLONG_MAX && dis[i][k]!=LLONG_MAX) {
                    dis[j][k]=min(dis[j][k], dis[j][i]+dis[i][k]); 
                    dis[k][j]=min(dis[k][j], dis[k][i]+dis[i][j]); 
                }
            }
        }
    }

    for (int i=0; i<Q; i++) {
        int a, b; cin>>a>>b; a--; b--; 

        if (dis[a][b]==LLONG_MAX) {
            cout<<-1<<'\n'; 
        } else {
            cout<<dis[a][b]<<'\n'; 
        }
    }

    return 0;
}