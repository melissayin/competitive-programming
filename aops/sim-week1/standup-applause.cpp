#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> farmers;
    for (int i = 0; i < N; i++) {
        int F;
        cin >> F;
        farmers.push_back(F);

    }

    sort(farmers.begin(), farmers.end());
    if (farmers[0] > 0) {
        cout << 0 << "\n";
    }
    else {
        bool solved = false;
        for (int i = 0; i < farmers.size(); i++) {
            if (farmers[i] <= i) {
                continue;
            }
            else {
                cout << i << "\n";
                solved = true;
                break;
            }
        }

        if (!solved) {
            cout << N << "\n";
        }
        


    }



    
}