#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long diagonal, value, y, x, big;
    cin >> y >> x;
       
    big = max(y, x);

    diagonal = 1 + (big - 1) * (2 + 2 * (big - 1)) / 2;
    
    long long difference;
    if (y > x) {
        difference = y - x;
        if (y % 2 == 1) {
            value = diagonal - difference;
        }
        else {
            value = diagonal + difference;
        }
    }
    else {
        difference = x - y;
        if (x % 2 == 1) {
            value = diagonal + difference;
        }
        else {
            value = diagonal - difference;
        }
    }
    cout << value << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}