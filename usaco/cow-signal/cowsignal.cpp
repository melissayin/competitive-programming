#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;

    for (int i = 0; i < m; i++) {
        string line;
        cin >> line;
        string newline;

        for (int a = 0; a < n; a++) {

            for (int b = 0; b < k; b++) {
                newline += line[a];
        
            }
        
        }

        for (int c = 0; c < k; c++) {
             cout << newline << "\n";
        
        }
      

    }
}