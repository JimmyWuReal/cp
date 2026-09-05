#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    int p; 
    cin >> n >> p; 

    const int INF = (1 << 30); 
    vector<int> d; 

    for (int i = 0; i < n; i++) {
        int h, g; 
        cin >> h >> g; 

        if (h > p) {
            cout << "No" << endl; 
            return 0; 
        }

        if (g == 0) {
            d.push_back(INF); 
        } else {
            int x = (p - h) / g + 1; 
            d.push_back(x); 
        }
    }

    sort(d.begin(), d.end()); 

    for (int i = 0; i < n; i++) {
        if (d[i] < i + 1) {
            cout << "No" << endl; 
            return 0; 
        }
    }

    cout << "Yes" << endl; 

    return 0;
}