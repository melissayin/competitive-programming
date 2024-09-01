#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;   
    long long solution = 0;
    int x = 1;
    while (pow(5, x) <= n) {
        solution += n / pow(5, x);
        x++;
    }
    cout << solution << "\n";
}