#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

ll encode(ll x, ll y) {
    return (x << 32) | y; 
}

struct Node {
    ll x, y; 
    int dist; 
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x0, y0, x1, y1; 
    cin >> x0 >> y0 >> x1 >> y1; 

    int n; 
    cin >> n; 

    unordered_set<ll> allowed; 

    for (int i = 0; i < n; i++) {
        ll r, a, b; 
        cin >> r >> a >> b; 

        for (ll c = a; c <= b; c++) {
            allowed.insert(encode(r, c)); 
        }
    }

    queue<Node> q; 

    q.push({x0, y0, 0}); 
    allowed.erase(encode(x0, y0)); 

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

    while(!q.empty()) {
        auto [x, y, dist] = q.front(); 
        q.pop(); 

        if (x == x1 && y == y1) {
            cout << dist << endl; 
            return 0; 
        }

        for (int d = 0; d < 8; d++) {
            ll nx = x + dx[d]; 
            ll ny = y + dy[d]; 

            ll key = encode(nx, ny); 

            if (allowed.count(key)) {
                allowed.erase(key); 
                q.push({nx, ny, dist + 1}); 
            }
        }
    }

    cout << -1 << endl; 

    return 0;
}