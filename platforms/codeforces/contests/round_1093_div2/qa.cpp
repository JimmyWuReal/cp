#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while(t--) { 
        int n; 
        cin >> n; 

        vector<int> nums(n); 
        for (int i = 0; i < n; i++) cin >> nums[i];

        unordered_set<int> seen;
        bool has_duplicate = false;
        for (int x : nums) {
            if (!seen.insert(x).second) {
                has_duplicate = true;
                break;
            }
        }

        if (has_duplicate) {
            cout << -1 << '\n';
            continue;
        }

        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << nums[i];
        }
        cout << '\n';
    }

    return 0;
}
