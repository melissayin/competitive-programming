#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int N, B;
    cin >> N >> B;

    vector<int> xpositions;
    vector<int> ypositions;

     for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ypositions.push_back(y);
        xpositions.push_back(x);

    }
    
    int a = 0; int b = 0;
    
    int answer = N;
    // iterating through all possibilities for a
    for (int i = 0; i < xpositions.size(); i++) {
        a = xpositions[i] + 1;
        // iterating through all possibilities for b
        for (int j = 0; j < ypositions.size(); j++) {
            b = ypositions[j] + 1;

            int q1 = 0;
            int q2 = 0;
            int q3 = 0;
            int q4 = 0;

            // going through all cows to determine quadrant
            for (int k = 0; k < xpositions.size(); k++) {
                int x = xpositions[k];
                int y = ypositions[k];

                if (x > a && y > b) {
                    q1++;
                }
                else if (x < a && y > b) {
                    q2++;
                }
                else if (x < a && y < b) {
                    q3++;
                }
                else if (x > a && y < b) {
                    q4++;
                }
                
            }

            int M = max({q1, q2, q3, q4});
            if (M < answer) {
                answer = M;
            }
        }
    }

    cout << answer << "\n";
}


/**
we want to iterate through all possibilities of (a, b) and
check each one for M, return smallest M

it's not reasonable to literally check every possibility of
(a, b) since B <= 1e6, but we know that checking multiple spaces
between two cows is redundant

so, the only possibilities we need to check are putting walls
between two adjacent cows in x and y --> since N <= 100, this is
only max 100^2 = 10000 possibilities, super fast

you can check for each coordinate z, put a wall at z+1 


* */