#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int count = 0;

    bool canPlay = true;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 6; j++) {
            if (j < i) {
                continue;
            }
            for (int k = 1; k <= 8; k++) {
                if (k < j) {
                    continue;
                }
                for (int l = 1; l <= 10; l++) {
                    if (l < k) {
                        continue;
                    }
                    for (int m = 1; m <= 12; m++) {
                        if (m < l) {
                            continue;
                        }
                        for (int n = 1; n <= 20; n++) {
                            if (n < m) {
                                continue;
                            }
                            count++;
                        }
                    }
            
                }
            }
        }
    }

    cout << count << "\n";

}