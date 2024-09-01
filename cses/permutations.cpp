#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    string evens = "", odds = "";
    string solution;
    if (n > 3 || n == 1) {
        for (int i = 1; i < (n + 1); i++) {
            if (i % 2 == 0) {
                evens += to_string(i);
                evens += " ";
            }
            else { 
                odds += to_string(i);
                odds += " ";
            }
            
        }
        solution = evens + odds;
    
    }
    else {
        solution = "NO SOLUTION";
    }

    cout << solution << "\n";

}
    
