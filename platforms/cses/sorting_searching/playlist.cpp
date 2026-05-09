#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    map<int, int> last_seen_pos; 

    int ans = 0; 
    int l = 0; 

    for (int r = 0; r < n; r++) {
        int x; 
        cin >> x; 

        if (last_seen_pos.count(x) && last_seen_pos[x] >= l) {
            l = last_seen_pos[x] + 1; 
        }

        last_seen_pos[x] = r; 

        ans = max(ans, r - l + 1); 
    }

    cout << ans; 

    return 0;
}