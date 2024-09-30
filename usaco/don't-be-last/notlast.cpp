#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int N;
    cin >> N;

    unordered_map<string, int> total_milk;

    for (int i = 0; i < N; i++) {
        string cow;
        int milk;
        cin >> cow >> milk;
        total_milk[cow] += milk;
    }

    int M = INT_MAX;
    if (total_milk.size() < 7) {
        M = 0;
    }
    else {
        for (auto &x: total_milk) {
            if (x.second < M) {
                M = x.second;
            }
        }
    }

    for (auto &x: total_milk) {
        x.second -= M;
    }

    int minimum = INT_MAX;
    for (auto &x: total_milk) {
        if (x.second < minimum && x.second != 0) {
            minimum = x.second;
        }
    }

    string answer;
    int count = 0;
    for (auto &x: total_milk) {
        if (x.second == minimum) {
            count++;
            answer = x.first;
        }
    }

    if (count != 1) {
        cout << "Tie\n";
    }
    else {
        cout << answer << "\n";
    }

   

}