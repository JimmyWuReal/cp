#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, sz, parity;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        parity.assign(n, 0);

        for (int i = 0; i < n; i++) parent[i] = i; 
    }

    int find(int x) {
        if (parent[x] == x) return x;

        int p = parent[x];
        parent[x] = find(parent[x]);
        parity[x] ^= parity[p];

        return parent[x];
    }

    bool unite(int a, int b, int w) {
        int ra = find(a);
        int rb = find(b);

        int pa = parity[a];
        int pb = parity[b];

        if (ra == rb) {
            return ((pa ^ pb) == w);
        }

        if (sz[ra] < sz[rb]) {
            swap(ra, rb);
            swap(pa, pb);
        }

        parent[rb] = ra;
        parity[rb] = pa ^ pb ^ w;

        sz[ra] += sz[rb];

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    DSU dsu(n);

    bool possible = true;

    for (int i = 0; i < n; i++) {
        int j, t;
        cin >> j >> t;
        j--;

        if (!dsu.unite(i, j, t)) {
            possible = false;
        }
    }

    if (possible)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}