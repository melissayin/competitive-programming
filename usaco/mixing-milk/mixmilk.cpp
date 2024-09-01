#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int a_cap;
    int a_amt;
    cin >> a_cap >> a_amt;

    int b_cap;
    int b_amt;
    cin >> b_cap >> b_amt;

    int c_cap;
    int c_amt;
    cin >> c_cap >> c_amt;

    int diff;

    for (int i = 0; i < 99; i += 3) {
        if (b_amt + a_amt > b_cap) {
            diff = b_amt + a_amt - b_cap;
            b_amt = b_cap;
            a_amt = diff;
        }
        else {
            b_amt += a_amt;
            a_amt = 0;
        }
        
        if (c_amt + b_amt > c_cap) {
            diff = c_amt + b_amt - c_cap;
            c_amt = c_cap;
            b_amt = diff;
        }
        else {
            c_amt += b_amt;
            b_amt = 0;
        }

        if (a_amt + c_amt > a_cap) {
            diff = a_amt + c_amt - a_cap;
            a_amt = a_cap;
            c_amt = diff;
        }
        else {
            a_amt += c_amt;
            c_amt = 0;
        }   
    }

    if (b_amt + a_amt > b_cap) {
            diff = b_amt + a_amt - b_cap;
            b_amt = b_cap;
            a_amt = diff;
    }
    else {
        b_amt += a_amt;
        a_amt = 0;
    }

    cout << a_amt << "\n" << b_amt << "\n" << c_amt << "\n";
     
}