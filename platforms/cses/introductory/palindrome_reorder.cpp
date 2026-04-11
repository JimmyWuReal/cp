#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // input 
    string s; 
    cin >> s; 

    unordered_map<char, int> map; 
    for (char c : s) map[c]++; 

    // solve 
    string res(s.size(), ' '); 
    int curr = 0; 

    for (const auto& pair : map) {
        int times = pair.second; 
        if (pair.second % 2 == 0) {
            for (int i = 0; i < times / 2; i++) {
                res[curr] = pair.first; 
                res[s.size() - 1 - curr] = pair.first; 

                curr++; 
            }
        } else {
            if (res[s.size() / 2] == ' ') {
                res[s.size() / 2] = pair.first; 
                times--; 

                for (int i = 0; i < times / 2; i++) {
                    res[curr] = pair.first; 
                    res[s.size() - 1 - curr] = pair.first; 

                    curr++; 
                }
            } else {
                cout << "NO SOLUTION"; 
                return 0; 
            }
        }
    }

    cout << res; 

    return 0;
}