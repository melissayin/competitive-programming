#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; 
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long N, X;
        cin >> N >> X;

        long long total = (N * (N + 1)) / 2;
        if (total % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        cout << "POSSIBLE\n";

        if (X==2) {
            long long target = total / 2;
            long long bessie = (int)( (-1 + sqrt(4 * total + 1) )/ 2);
            cout << bessie << "\n";
            
        }

       
        
    }



}