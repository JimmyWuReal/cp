#include <bits/stdc++.h>
using namespace std;

int pos = -1; 

long long dp(vector<string>& tk) {
    pos++; 

    string s = tk[pos]; 

    if (pos == tk.size()) return 0; 

    if (s == "+") {
        long long a = dp(tk); 
        long long b = dp(tk); 

        return a + b;
    } else if (s == "-") {
        long long a = dp(tk); 
        long long b = dp(tk); 

        return a - b; 
    } else if (s == "*") {
        long long a = dp(tk); 
        long long b = dp(tk); 

        return a * b; 
    } else if (s == "/") {
        long long a = dp(tk); 
        long long b = dp(tk); 

        return a / b; 
    } else {
        return stoi(s); 
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<string> tokens(n); 
    for (int i = 0; i < n; i++) cin >> tokens[i]; 
    
    int k; 
    cin >> k; 

    vector<string> change = tokens;

    for (int i = 0; i < k; i++) {
        int x; 
        cin >> x; 

        x--; 

        if (change[x] == "+") change[x] = "-"; 
        else if (change[x] == "-") change[x] = "+"; 
        else if (change[x] == "*") change[x] = "/"; 
        else if (change[x] == "/") change[x] = "*"; 
    }

    pos = -1; 
    long long res1 = dp(tokens); 
    pos = -1; 
    long long res2 = dp(change); 

    cout << res1 << endl << res2 << endl; 

    return 0;
}