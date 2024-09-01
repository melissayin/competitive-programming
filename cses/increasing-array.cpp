#include <bits/stdc++.h>
using namespace std;


int main() {
    int size;
    cin >> size;
    int array[size];
    cin >> array[0];
    long long moves = 0;
    for (int i = 1; i < size; i++) {
        cin >> array[i];
        if (array[i] < array[i-1]) {
            moves += array[i-1] - array[i];
            array [i] = array[i-1];
        }
    }

    cout << moves << "\n";
}