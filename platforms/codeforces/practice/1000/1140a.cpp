#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<int> pages(n);
    for (auto &x : pages) cin >> x; 

    int days = 1;
    int to = 0; 

    for (int i = 0; i < n; i++) {
        if (i > to) {
            days++; 
        }

        to = max(to, pages[i] - 1); 
        to = max(i, to); 
    }

    cout << days << endl; 

    return 0;
}