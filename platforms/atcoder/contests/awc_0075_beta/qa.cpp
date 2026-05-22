#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 
    
    int last = 0;
    cin >> last; 
    
    int change = 0; 
    int cnt = 0; 

    for (int i = 0; i < n - 1; i++) {
        int temp; 
        cin >> temp; 

        if (temp > last) {
            if (change == -1) {
                cnt++; 
            } 
            change = 1; 
            last = temp; 
        } else if (temp < last) {
            if (change == 1) {
                cnt++; 
            }
            change = -1; 
            last = temp; 
        } else {
            change = 0; 
        }
    }

    cout << cnt << endl; 

    return 0;
}