#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> nums(n); 
    for (int i = 0; i < n; i++) cin >> nums[i]; 

    unordered_set<int> seen;

    int cnt = 0; 

    for (int x : nums) {
        if (!seen.count(x - 1)) { 
            cnt++; 
        }
        seen.insert(x); 
    }


    cout << cnt << endl; 

    return 0;
}