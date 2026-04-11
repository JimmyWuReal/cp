#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    int cnt = 0; 

    for(int i = 5; i <= n; i += 5) {
        int temp = i; 

        while (temp % 5 == 0) {
            temp /= 5; 
            cnt++; 
        }
    }

    cout << cnt; 

    return 0;
}