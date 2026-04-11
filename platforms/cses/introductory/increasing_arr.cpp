#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<int> nums(n); 
    for (int i = 0; i < n; i++) cin >> nums[i]; 

    long long cnt = 0; 

    for (int i = 1; i < n; i++) { 
        if (nums[i] < nums[i-1]) {
            cnt += nums[i-1] - nums[i]; 
            nums[i] = nums[i-1]; 
        }    
    }

    cout << cnt; 
    
    return 0;
}