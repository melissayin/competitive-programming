#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    vector<int> ids; 
    vector<int> sorted;

    int count = 0; 
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        ids.push_back(A);
        sorted.push_back(A);
    }

    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < N; i++) {
        if (sorted[i] != ids[i]) {
            count++;
        }
    }

    cout << count << "\n";

}