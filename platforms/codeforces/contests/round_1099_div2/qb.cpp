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

        vector<long long> nums(n); 
        for (int i = 0; i < n; i++) cin >> nums[i]; 

        long long k = 0; 

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                k = max(k, nums[i] - nums[i + 1]); 
            }
        }

        if (k == 0) {
            cout << "YES" << endl; 
            continue;
        }

        bool d0 = true; 
        bool d1 = true; 

        for (int i = 0; i < n - 1; i++) {
            bool t0 = false; 
            bool t1 = false; 

            for (int x = 0; x <= 1; x++) {
                bool pos = (x == 0 ? d0 : d1); 
                if (!pos) continue;

                for (int y = 0; y <= 1; y++) {
                    long long l = nums[i] + x * k; 
                    long long r = nums[i + 1] + y * k; 

                    if (l <= r) {
                        if (y == 0) t0 = true; 
                        else t1 = true; 
                    }
                }
            }

            d0 = t0; 
            d1 = t1; 
        }

        cout << (d0 || d1 ? "YES" : "NO") << endl; 
    }

    return 0;
}