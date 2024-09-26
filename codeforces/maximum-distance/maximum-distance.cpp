#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> x_coords;
    vector<int> y_coords;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x_coords.push_back(x);
    
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        y_coords.push_back(x);
    }

    int distance = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x_diff = x_coords[j] - x_coords[i];
            int y_diff = y_coords[j] - y_coords[i];

            int new_dist = x_diff * x_diff + y_diff * y_diff;
    
            if (new_dist > distance) {
                distance = new_dist;
            }
        }
    }

    cout << distance << "\n";
}