#include <bits/stdc++.h>
using namespace std;

int bit[200000]; 

void add(int i, int x, int n) {
    while (i <= n) {
        bit[i] += x; 
        i += i & -i; 
    }
}

int sum(int i) {
    int s = 0; 
    while (i > 0) {
        s += bit[i]; 
        i -= i & -i; 
    }

    return s; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<int> pos(n + 1); 

    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x; 

        pos[x] = i; 
        add(i, 1, n); 
    }

    for (int i = 1; i <= n; i++) {
        cout << sum(pos[i]) << endl; 
        add(pos[i], -1, n); 
    }

    return 0;
}