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
        for (int i = 0; i < n; i++) cin >> nums[i];

        bool found = false;

        for (int i = 0; i < n - 1 && !found; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] != 0 && (nums[j] % nums[i]) % 2 == 0 && !found) {
                    cout << nums[i] << " " << nums[j] << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "-1" << endl;
        }
    }

    return 0;
}