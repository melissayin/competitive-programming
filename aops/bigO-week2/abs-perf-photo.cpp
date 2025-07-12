#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    vector<int> gueCows;
    vector<int> holCows;
    vector<tuple<int, string>> allCows;
    
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        allCows.push_back(make_tuple(x, "gue"));
    }
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        allCows.push_back(make_tuple(x, "hol"));
    }

    sort(allCows.begin(), allCows.end());

    int minDiff = INT_MAX;
    for (int i = 0; i < allCows.size() - 1; i++) {
        if (get<1>(allCows[i]) != get<1>(allCows[i + 1]) ) {
            int diff = get<0>(allCows[i + 1]) - get<0>(allCows[i]);
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
    }

    cout << minDiff << "\n";
    

}