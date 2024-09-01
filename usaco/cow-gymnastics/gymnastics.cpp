#include <bits/stdc++.h>
using namespace std;

const int K = 10;
const int N = 20;

int k, n;
int rankings[K][N]; // vector<vector<int>> rankings(K, vector<int>(N));

bool consistent(int cow1, int cow2) {
    // true if cow1 always does better than cow2
    
    for (int i = 0; i < k; i++) {
        int pos1, pos2;

        for (int j = 0; j < n; j++) {
            if (rankings[i][j] == cow1) {
                pos1 = j; 
            }
            if (rankings[i][j] == cow2) {
                pos2 = j;
            }

        }

        if (pos1 > pos2) {
            return false;
        }

    }

    return true;

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    cin >> k >> n;

    int count = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rankings[i][j];
        }
    }

    for (int cow1 = 1; cow1 < n + 1; cow1++) {
        for (int cow2 = cow1 + 1; cow2 < n + 1; cow2++) {
            if (consistent(cow1, cow2) || consistent(cow2, cow1)) {
                count++;
            }
    
        }
    }

    cout << count << "\n";
     
}


/*
1 <= K <= 10
1 <= N <= 20

max possible pairs -> Nc2 = 190

lets check every possible pair 
for each pair, check if its consistent

O(kn^3)
for cow1 from 1 to N: O(n)
    for cow2 from cow1+1 to N: <- O(n)
        if **consistent(cow1, cow2)**: <- O(kn)
            ans++;

consistent(cow1, cow2): <- O(kn)
    true if for every ranking from 1 to k, pos(cow1) < pos(co2)
    for ranking from 1 to k: <- O(kn)
        find the position of cow1 <- O(n) 
       find the position of cow2 <- O(n)
        if its pos(cow1) < pos(cow2) then we can keep going
        if its not then return false

10*20^3 ~~~ 80k operations
*/