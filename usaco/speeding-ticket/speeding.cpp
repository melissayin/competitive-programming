#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> road;
    vector<int> bessie;

    for (int i = 0; i < n; i++) {
        int len, limit;
        cin >> len >> limit;

        for (int a = 0; a < len; a++) {
            road.push_back(limit);
            
        }
    }

    for (int i = 0; i < m; i++) {
        int len, b_speed;
        cin >> len >> b_speed;

        for (int a = 0; a < len; a++) {
            bessie.push_back(b_speed);
        }
    }

    int diff = 0;

    for (int i = 0; i < 100; i++) {
        int newdiff = 0;
        if (bessie[i] > road[i]) {
            newdiff = bessie[i] - road[i];
        }

        if (newdiff > diff) {
            diff = newdiff;
        }
    }

    cout << diff << "\n";

}