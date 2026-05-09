#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<int> nums(n); 
    for (int i = 0; i < n; i++) cin >> nums[i]; 

    int x; 
    cin >> x; 

    cout << nums[x - 1] << endl; 

    return 0;
}