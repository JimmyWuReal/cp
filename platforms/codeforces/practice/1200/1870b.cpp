#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        int n, m; 
        cin >> n >> m; 

        vector<int> nums(n); 
        for (auto &x : nums) cin >> x; 

        int mask = 0; 

        for (int i = 0; i < m; i++) {
            int x; 
            cin >> x; 

            mask = mask | x; 
        }

        int small = 0; 
        int big = 0; 

        if (n % 2 == 0) {
            for (int x : nums) {
                small = small ^ (x | mask); 
                big = big ^ x; 
            }
        } else {
            for (int x : nums) {
                small = small ^ x; 
                big = big ^ (x | mask); 
            }
        }

        cout << small << " " << big << endl; 
    }

    return 0;
}

// had completely no idea. 
// got some hints from GPT.  
// after getting the hints, understand the question mostly and can think about a near perfect solution. still got some problems being corrected. 
// the problem is that I didn't understand the question well, or I might be able to solve this without hints 