#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, x; 
    cin >> t >> x; 

    vector<int> read(t + 1); 
    for (int i = 0; i <= t; i++) cin >> read[i]; 

    int saved = read[0]; 

    cout << "0 " << read[0] << endl; 

    for (int i = 1; i <= t; i++) {
        if (abs(read[i] - saved) >= x) {
            saved = read[i]; 

            cout << i << " " << read[i] << endl; 
        }
    }

    return 0;
}