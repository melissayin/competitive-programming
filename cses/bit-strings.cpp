#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;
    long long mod = 1000000000 + 7;
    long long solution = 1;
    for (long long i = 0; i < n; i++) {
        solution = (solution * 2) % mod;
    }
    
    cout << solution << "\n";
    


}