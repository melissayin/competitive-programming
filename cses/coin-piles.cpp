#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int difference = a - b;
    if (difference < 0) {
        difference *= -1;
    }

    int x = max(a, b) - 2 * difference;
    if (x % 3 == 0 && x >= 0) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}