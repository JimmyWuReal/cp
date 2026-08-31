#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> ss; 
    string s; 

    int m = 0; 

    while (getline(cin, s)) {
        ss.push_back(s); 
        if (s.size() > m) m = s.size(); 
    }

    int c = ss.size(); 

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < c; j++) {
            int idx = c - j - 1; 
            if (ss[idx].size() < i + 1) {
                cout << " "; 
            } else {
                cout << ss[idx][i]; 
            }
        }

        cout << endl; 
    }

    return 0;
}