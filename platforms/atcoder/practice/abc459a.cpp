#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    n--; 

    string s = "HelloWorld"; 

    s.erase(s.begin() + n); 

    cout << s << endl; 

    return 0;
}