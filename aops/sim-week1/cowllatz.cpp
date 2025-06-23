#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int count = 0;

    while (N != 1) {
        count++;
        if (N % 2 == 0) {
            N /= 2;
        }
        else {
            N *= 3;
            N++;
        }
    }

    count++;

    cout << count << "\n";

}