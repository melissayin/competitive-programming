#include <bits/stdc++.h>
using namespace std;


int main() {
    string DNA;
    cin >> DNA;
    int count = 1, solution = 1;
    for (int i = 1; i < DNA.length(); i++) {
        if (DNA[i] == DNA[i-1]) {
            count += 1;
            if (count > solution) {
                solution = count;
            }
        }
        else {
            count = 1;
        }
    }

    cout << solution << "\n";
}