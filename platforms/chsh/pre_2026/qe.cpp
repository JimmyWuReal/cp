// Code written by Jimmy Wu (JingZe Wu) 
// AC during the contest 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; 
    cin >> n >> k; 

    if (k > (n - 1) * 255) {
        cout << -1 << endl; 
        return 0; 
    }

    int last = 0; 
    int left = k; 
    vector<int> res; 

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            last = 0; 
            res.push_back(0); 
        } else if (left >= 255) {
            if (last == 0) {
                last = 255; 
                res.push_back(255);
            } else {
                last = 0; 
                res.push_back(0); 
            }

            left -= 255; 
        } else if (left > 0) {
            if (last == 0) {
                last = left; 
                res.push_back(left); 
            } else {
                last = 255 - left; 
                res.push_back(255 - left); 
            }

            left = 0; 
        } else {
            res.push_back(last); 
        }
    }

    for (int i : res) cout << i << " "; 

    return 0;
}