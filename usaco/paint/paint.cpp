#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int solution;
    
    if (a > c) {
        int temp = a;
        a = c;
        c = temp;

        temp = b;
        b = d;
        d = temp;
    }

    if (b <= c) {
        solution = (b - a) + (d - c);
    }
    else {
        solution = max(b, d) - a;
    }
    cout << solution;
}