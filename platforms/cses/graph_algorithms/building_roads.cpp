#include <bits/stdc++.h>
using namespace std;

class DSU {
private: 
    vector<int> parent; 
    vector<int> sz; 

public: 
    DSU(int N) {
        parent.resize(N); 
        sz.assign(N, 1); 
        for (int i=0; i<N; i++) parent[i]=i; 
    }

    int find(int x) {
        if (parent[x]==x) return x; 
        return parent[x]=find(parent[x]); 
    }

    bool connected(int a, int b) {
        return find(a)==find(b); 
    }

    void unite(int a, int b) {
        a=find(a); b=find(b); 
        if (sz[a]<sz[b]) swap(a, b); 
        parent[b]=parent[a]; 
        sz[a]+=sz[b]; 
    }

    int size(int x) {
        return sz[find(x)]; 
    }
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 

    DSU dsu(N); 

    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b; 
        dsu.unite(a-1, b-1); 
    }

    vector<pair<int, int>> res; 

    for (int i=1; i<N; i++) {
        if (!dsu.connected(0, i)) {
            res.push_back({0, i}); 
            dsu.unite(0, i); 
        }
    } 

    cout<<res.size()<<'\n';
    for (auto &[a, b] : res) cout<<a+1<<' '<<b+1<<'\n'; 

    return 0;
}