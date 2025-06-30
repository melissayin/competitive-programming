#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int P, R, K;
    cin >> P >> R >> K;
   
    int numCycles = R % P;

    int startK = K;
    int endK = 0;
    int left = 0;
    if (startK % 2 == 1) {
        endK = startK + numCycles;
        while (endK > P) {
            endK -= P;
        }

         int leftInd = endK - 1;
        if (leftInd == 0) {
            leftInd = P;
        }

        int i = 0;
        while (i < numCycles ) {
            leftInd++ ;
            if (leftInd > P) {
                leftInd -= P;
            }
            i++;
        }

        left = leftInd;

    }
    else {
        endK = startK - numCycles;
        while (endK < 1) {
            endK += P;
        }

        int leftInd = endK - 1;
        if (leftInd == 0) {
            leftInd = P;
        }


        int i = 0;
        while (i < numCycles ) {
            leftInd-- ;
            if (leftInd == 0) {
                leftInd = P;
            }
            i++;
        }

        left = leftInd;

    }
    


   // cout << startK << " end" << endK << "\n";

   
    

    int right = left + 2;
    if (right > P) {
        right -= P;
    }

    cout << left << " " << right << "\n";



}