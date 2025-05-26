#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;
        vector<string> photo(N);
        for (int i = 0; i < N; ++i) {
            cin >> photo[i];
        }

        int min_stars = 0;
        int pairs = 0;
        bool possible = true;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (photo[i][j] == 'B') {
                    if (i - B >= 0 && j - A >= 0 && photo[i - B][j - A] == 'B') {
                        min_stars+=2;
                        if(!(A==0 && B == 0)) {
                            pairs++;
                        }
                        
                    } 
                    else if (i - B >= 0 && j - A >= 0 && photo[i - B][j - A] == 'G') {
                        min_stars+=2;
                        if(!(A==0 && B == 0)) {
                            pairs++;
                        }
                    }
                    else {
                        possible = false;
                    }
                } 
                else if (photo[i][j] == 'G') {
                    if ((i - B >= 0 && j - A >= 0 && photo[i - B][j - A] == 'B') ||
                        (i + B < N && j + A < N && photo[i + B][j + A] == 'B')) {
                        if(!(A==0 && B == 0)) {
                            pairs++;
                        }
                        min_stars++;
                    } else {
                        min_stars++;
                    }
                }
            }
        }

        if (possible) {
            if (pairs == 0) {
                cout << min_stars << "\n";
            }
            else 
            cout << min_stars  - pairs + 1 << "\n";
        } 
        else {
            cout << -1 << "\n";
        }
    }

}
