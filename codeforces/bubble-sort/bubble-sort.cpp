#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> input;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    int swapCount = 0;
    for (int i = 0; i < n; i++) {
    
        for (int j = 0; j < n - 1; j++) {
            if (input[j] > input[j + 1]) {
                swap(input[j], input[j + 1]);
                swapCount++;
            }
        }
    
    }

    cout << "Array is sorted in " << swapCount << " swaps.\n";
    cout << "First Element: " << input[0] << "\n";
    cout << "Last Element: " << input[n-1] << "\n";
}