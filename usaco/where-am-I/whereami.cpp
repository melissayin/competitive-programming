#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N;  
    string input;
    cin >> N >> input; 

    for (int k = 1; k < N + 1; k++) {
        unordered_set<string> subsequences;

        for (int j = 0; j < N - k + 1; j++) {
            string current_boxes = input.substr(j, k); 
            subsequences.insert(current_boxes);
        }
       
        if (subsequences.size() == N - k + 1) {
            cout << k << "\n";
            break;
        }

    }
    
}
