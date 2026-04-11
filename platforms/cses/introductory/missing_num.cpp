#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    // unordered set for all number from 1 to n 
    unordered_set<int> nums; 

    for (int i = 0; i < n - 1; i++) {
        int x; 
        cin >> x; 
        nums.insert(x); 
    }

    for (int i = 1; i <= n; i++) {
        if (!nums.count(i)) {
            cout << i; 
            break; 
        }
    }

    return 0; 
}