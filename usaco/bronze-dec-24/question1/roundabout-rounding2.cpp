#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        int digits = 0;
        int count = 0;
        int Ntemp = N;
        while (N != 0) {
            N /= 10;
            digits++;
        }

        for (int i = 1; i <= digits; i++) {
            int currCount = 0;
            if (i == 1) {
                currCount = 0;
                continue;
            }
            
            int up = min((int) (5*pow(10, i-1)) - 1, Ntemp);
           
           // cout << "up = " << up << "\n";
            int low = 0;
            for (int j = 0; j < i; j++) {
                low += 4 * pow(10, j);
            }
            //cout << "low = " << low << "\n";

            currCount = up - low;
            if (currCount < 0) {
                currCount = 0;
            }
            count += currCount; 
        }

        //count = max(0, count - 3);
        cout << count << "\n";
    }
}

    
