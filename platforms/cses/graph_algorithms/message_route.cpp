#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 
    vector<vector<int>> adj(N+1); 

    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b; 
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    vector<int> parent(N+1, -1); 
    queue<int> q; 

    q.push(1); 
    parent[1]=0; 

    while (!q.empty()) {
        int u=q.front(); 
        q.pop(); 

        for (int v : adj[u]) {
            if (parent[v]==-1) {
                parent[v]=u; 
                q.push(v); 
            }
        }
    }

    if (parent[N]==-1) {
        cout<<"IMPOSSIBLE"<<'\n'; 
        return 0; 
    }

    vector<int> path; 
    int curr=N; 

    while (curr!=0) {
        path.push_back(curr); 
        curr=parent[curr]; 
    }

    reverse(path.begin(), path.end()); 

    cout<<path.size()<<'\n'; 

    for (int node : path) {
        cout<<node<<' '; 
    }

    cout<<'\n'; 

    return 0; 
}