#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m; 

    int res = 0; 

    for (int i = 0; i < n; i++) {
        vector<int> street(m); 
        for (int j = 0; j < m; j++) cin >> street[j]; 

        res = max(res, *min_element(street.begin(), street.end())); 
    }

    cout << res << endl; 

    return 0;
}