#include <bits/stdc++.h>
using namespace std;

class DSU {
public: 
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n); 
        sz.assign(n, 1); 

        for (int i = 0; i < n; i++) parent[i] = i; 
    }

    int find(int x) {
        if (parent[x] == x) return x; 
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a); 
        b = find(b); 

        if (a == b) return false; 

        if (sz[a] < sz[b]) swap(a, b); 
        
        parent[b] = a; 
        sz[a] += sz[b]; 

        return true; 
    }

    bool same(int a, int b) {
        return find(a) == find(b); 
    }
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t; 

    set<int> blocked; 

    for (int i = 0; i < k; i++) {
        int x; 
        cin >> x; 
        blocked.insert(x); 
    }

    DSU dsu(n); 

    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; 

        if (blocked.count(a) || blocked.count(b)) continue;

        dsu.unite(a - 1, b - 1); 
    }

    if (dsu.same(s - 1, t - 1)) {
        cout << "Yes" << endl; 
    } else {
        cout << "No" << endl; 
    }

    return 0;
}