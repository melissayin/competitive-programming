#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    if (N == 0) {
        cout << -1 << "\n";
    }
    else {
        set<long long> seenDigits;
        long long currNum = N;

        while (true) {

            long long temp = currNum;
            while (temp > 0) {
                int digit = temp % 10;
                seenDigits.insert(digit);
                temp /= 10;
            }

            if (seenDigits.size() == 10){
                break;
            }
            currNum += N;
            
        }

        cout << currNum << "\n";

        }

    

}