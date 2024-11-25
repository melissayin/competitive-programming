#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int N;
    cin >> N;
    unordered_map<string, string> names;
    for (int i = 0; i < N; i++) {
        string city, state;
        cin >> city >> state;
        city = city.substr(0, 2);
        names[city] = state;
    }
    int total = 0;
    unordered_map<string, int> counts; 
    for (auto &i: names) {
        if (i.first != i.second) {
            total += counts[i.first + i.second];
            counts[i.second + i.first]++;
        }
    }
    

    cout << total <<  "\n";
  
}

/*
for (auto &i: names) {
        for (auto &j: names) {
            if (i.first == j.second && j.first == i.second && j.second != i.second && i.first != i.second && j.first != j.second) {
                string pair = i.first + i.second + j.first + j.second;
                string pair2 = j.first + j.second + i.first + i.second;
                good_pairs.insert(pair);
                good_pairs.insert(pair2);

            }
        }
    }
*/