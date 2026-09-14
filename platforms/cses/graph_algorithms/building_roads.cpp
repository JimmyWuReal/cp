#include <bits/stdc++.h>
using namespace std;

class DSU {
public: 
    vector<int> parent; 

    DSU(int N) {
        parent.resize(N); 
        for (int i=0; i<N; i++) parent[i]=i; 
    }

    int find(int x) {
        if (parent[x]==x) return x; 
        
        return parent[x]=find(parent[x]); 
    }

    void unite(int a, int b) {
        a=find(a); 
        b=find(b); 

        if (b>a) swap(a, b); 

        parent[a]=b; 
    }

    vector<int> get() {
        int N=parent.size(); 
        vector<int> temp; 
        for (int i=0; i<N; i++) {
            if (find(i)==i) temp.push_back(i+1); 
        }

        return temp; 
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

    vector<int> res=dsu.get(); 

    cout<<res.size()-1<<'\n'; 

    for (int i=0; i<res.size()-1; i++) {
        cout<<res[i]<<' '<<res[i+1]<<'\n'; 
    }

    return 0; 
}