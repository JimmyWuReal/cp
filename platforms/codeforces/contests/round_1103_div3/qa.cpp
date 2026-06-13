#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        int n; 
        cin >> n; 

        vector<int> nums(n); 
        for (auto &x : nums) cin >> x; 

        cout << *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()) + 1 << endl; 
    }

    return 0;
}