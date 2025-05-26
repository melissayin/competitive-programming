#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    unordered_map<int, vector<int>> positions;
    for (int i = 0; i < N; ++i) {
        positions[a[i]].push_back(i);
    }

    unordered_set<string> moos;

    for (int j = 0; j < N; ++j) {
        for (int k : positions[a[j]]) {
            if (k > j) {
                for (int i = 0; i < j; ++i) {
                    if (a[i] != a[j]) {
                        moos.insert(to_string(a[i]) + " " + to_string(a[j]) + " " + to_string(a[k]));
                    }
                }
            }
        }
    }

    cout << moos.size() << endl;

}
