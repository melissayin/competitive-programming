#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long J0, J1, N, K;
    cin >> J0 >> J1 >> N >> K;

    /*
    x 0 
    0x + y 1 0
    1x + y 2 
    1x + 2y 3 
    2x + 3y 4
    3x + 5y 5
    5x + 8y
    8x + 13y
    
    */
    long long prev = J1;
    long long prev2 = J0;
    long long curr = 0;

    long long fib = (pow((1 + sqrt(5.0)) / 2.0 , N) + pow((1 - sqrt(5.0)) / 2.0, N)) / sqrt(5.0);
    fib = fib % 1000;
    

    if (K == 1) {
        cout << curr % 10 << "\n";
    }
    else if (K == 2) {
        cout << curr % 100 << "\n";
    }
    else {
        cout << curr % 1000 << "\n";
    }
    /*
    for (long long i = 0; i < N - 1; i++) {
        curr = prev + prev2;
       // cout << curr << " ";
        prev2 = prev;
        prev = curr;
       
        
        curr = curr % 1000;
        

    }*/

}