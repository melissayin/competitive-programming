#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> pebble_pos(4);
    for (int i = 1; i < 4; i++) {
        pebble_pos[i] = i;
    }

    vector<int> correct_guess(4);

    for (int i = 0; i < n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        for (int x = 1; x < 4; x++) {  

            if (a == pebble_pos[x]) {
                pebble_pos[x] = b;
            }
            else if (b == pebble_pos[x]) {
                pebble_pos[x] = a;
            }
            if (g == pebble_pos[x]) {
                correct_guess[x] += 1; 
            }
            
        }
    }
    
    int max = 0;
    for (int i: correct_guess) {
       if (i > max) {
            max = i;
       }

    }

    cout << max << "\n";
}