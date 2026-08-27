#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    long long all = 0;
    multiset<long long> nums;

    while (q--) {
        int x;
        cin >> x;

        if (x == 1) {
            long long y;
            cin >> y;

            nums.insert(y - all);
        } else if (x == 2) {
            long long y;
            cin >> y;

            all += y;

        } else {
            long long mn = *nums.begin();
            nums.erase(nums.begin());

            cout << mn + all << '\n';
        }
    }

    return 0;
}