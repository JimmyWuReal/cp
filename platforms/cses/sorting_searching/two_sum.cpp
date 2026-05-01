#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
 
    vector<int> nums(n);
    map<int, int> seen;
 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
 
        int need = x - nums[i];
 
        if (seen.count(need)) {
            cout << seen[need] + 1 << " " << i + 1 << '\n';
            return 0;
        }
 
        seen[nums[i]] = i;
    }
 
    cout << "IMPOSSIBLE\n";
 
    return 0;
}
