#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> road; 
vector<int> parent; 
vector<int> visited; 

int cs=-1; 
int ce=-1; 

bool dfs(int x, int p) {
    visited[x]=1; 
    parent[x]=p; 

    for (int r : road[x]) {
        if (r==p) continue;

        if (visited[r]) {
            cs=r; 
            ce=x; 
            return true; 
        }

        if (dfs(r, x)) return true; 
    }

    return false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 

    road.resize(N); 
    parent.assign(N, -1); 
    visited.assign(N, 0); 

    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b; 
        a--; b--; 
        road[a].push_back(b); 
        road[b].push_back(a); 
    }

    for (int i=0; i<N; i++) {
        if (!visited[i] && dfs(i, -1)) break; 
    }

    if (cs==-1) {
        cout<<"IMPOSSIBLE\n"; 
        return 0; 
    }

    vector<int> c; 
    c.push_back(cs); 
    for (int x=ce; x!=cs; x=parent[x]) c.push_back(x); 
    c.push_back(cs);   

    cout<<c.size()<<'\n'; 
    for (int x : c) cout<<x+1<<' '; 

    cout<<'\n'; 
    
    return 0; 
}