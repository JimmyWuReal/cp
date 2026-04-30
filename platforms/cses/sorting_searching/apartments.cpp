#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;

    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; i++) cin >> applicants[i];
    for (int i = 0; i < m; i++) cin >> apartments[i];

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int a = 0; 
    int b = 0; 
    int ans = 0;

    while (a < n && b < m) {
        if (apartments[b] < applicants[a] - k) {
            b++;
        } else if (apartments[b] > applicants[a] + k) {
            a++;
        } else {
            ans++;
            a++;
            b++;
        }
    }

    cout << ans << "\n";

    return 0;
}