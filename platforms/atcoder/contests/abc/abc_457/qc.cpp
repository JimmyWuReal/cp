#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k; 
    cin >> n >> k; 

    vector<pair<int, vector<int>>> seq(n); 

    for (int i = 0; i < n; i++) {
        int l; 
        cin >> l;
        seq[i].second.resize(l);
        for (int j = 0; j < l; j++) cin >> seq[i].second[j]; 
    }

    for (int i = 0; i < n; i++) cin >> seq[i].first;  

    // solve 

    long long res = 0; 

    for (int i = 0; i < n; i++) {

        long long times = seq[i].first; 
        vector<int> nums = seq[i].second; 
        long long len = nums.size(); 

        if (res + times * len >= k) {
            cout << nums[(k - res - 1) % len] << endl; 
            return 0; 
        } else {
            res += times * len; 
        }
    }

    return 0;
}