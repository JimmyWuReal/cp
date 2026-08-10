#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<int> ice(n); 
    for (auto &x : ice) cin >> x; 

    sort(ice.begin(), ice.end()); 

    vector<int> res(n); 

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            res[i] = ice[n / 2 + i / 2]; 
        } else {
            res[i] = ice[i / 2]; 
        }
    }

    int cnt = 0; 

    for (int i = 1; i < n - 1; i++) {
        if (res[i] < res[i - 1] && res[i] < res[i + 1]) cnt++; 
    }

    cout << cnt << endl; 

    for (int i : res) {
        cout << i << " "; 
    }

    cout << endl; 

    return 0;
}