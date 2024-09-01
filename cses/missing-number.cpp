#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;
    long long sum = n*(n + 1)/2;
    long long sum2 = 0;

    for (int i = 0; i < n - 1; i++) {
        long long x;
        cin >> x;
        sum2 += x;
    }
    cout << sum - sum2 << "/n";
}