#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    vector<int> gueCows;
    vector<int> holCows;
    
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        gueCows.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        holCows.push_back(x);
    }

    sort(gueCows.begin(), gueCows.end());
    sort(holCows.begin(), holCows.end());

    int size = min(M, N);

    for (int i = 0; i < size; i++) {

    }

}