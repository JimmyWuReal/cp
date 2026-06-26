#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; 
    string n; 

    cin >> s >> n; 

    unordered_map<char, int> letters; 

    for (char c : n) {
        letters[c]++; 
    }

    int y = 0; 

    string temp = ""; 

    for (char c : s) {
        if (letters[c] > 0) {
            letters[c]--;
            y++; 
        } else {
            if (islower(c)) {
                temp.push_back(toupper(c)); 
            } else {
                temp.push_back(tolower(c)); 
            }
        }
    }

    int w = 0;
    
    for (char c : temp) {
        if (letters[c] > 0) {
            letters[c]--; 
            w++; 
        }
    }

    cout << y << " " << w << endl; 

    return 0;
}