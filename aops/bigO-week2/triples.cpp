#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int total = 0;
    for (int a = 2; a <= 200; a++) {
        for (int b = 2; b <= 200; b++) {
            for (int c = 2; c <= 200; c++) {
                if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                    total++;
                }
            
            }
        }
    }

    cout << total / 2 << "\n";

}