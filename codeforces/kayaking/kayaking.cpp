#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> weights;

    int total = 0;
    for (int i = 0; i < 2*n; i++ ) {
        int a;
        cin >> a;
        weights.push_back(a);
        total += a;
    }

    sort(weights.begin(), weights.end());

    
    for (int i = 0; i < 2*n; i ++) {
       
        for (int j = i + 1; j < 2*n; j++) {
            vector<int> temp_weights;

            int temp_total = 0; 

            for (int k = 0; k < weights.size(); k++) {
                if (k == i || k == j) {
                    continue;
                }
                temp_weights.push_back(weights[k]);
            }

            for (int k = 0; k < temp_weights.size() - 1; k += 2) {
                int instability = temp_weights[k + 1] - temp_weights[k];
                temp_total += instability;
            }

            if (temp_total < total) {
                total = temp_total;
            }
        }
    }
    
    cout << total << "\n";

}