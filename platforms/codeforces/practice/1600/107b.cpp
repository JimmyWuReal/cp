#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, h; 
    cin >> n >> m >> h; 

    n--; 

    vector<int> departments(m); 
    for (int &x : departments) cin >> x; 

    int players = accumulate(departments.begin(), departments.end(), 0); 

    players--; 

    if (players < n) {
        cout << -1 << endl; 
        return 0; 
    } else { 
        players--; 
        int choose = departments[h - 1] - 1; 

        if (n > players - choose) {
            cout << -1 << endl; 
            return 0; 
        } 

        float percentage = 1; 

        for (int i = n; i < 0; i--) {
            percentage /= players; 
            percentage *= players - choose; 

            players--; 
            choose--; 
        }

        cout << percentage << endl; 
        return 0; 
    }

    return 0;
}