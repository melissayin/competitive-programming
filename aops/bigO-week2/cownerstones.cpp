#include <bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>> rows) {
    int maxSum = 0;
    // find max in row
    // check all corresponding column sums 

    for (int i = 0; i < rows.size(); i++) {
        int currSum = 0;
        vector<int> r = rows[i];
        int max1 = -1;
        int ind = -1;
        for (int j = 0; j < r.size(); j++) {
            if (r[j] > max1) {
                max1 = r[j];
                ind = j;
            }
        }

        int max2 = -1;
        int ind2 = -1;
        for (int j = 0; j < r.size(); j++) {
            if (r[j] > max2 && j != ind) {
                max2 = r[j];
                ind2 = j;
                
            }
        }
        int rowSum = max1 + max2;

        //cout << ind << " " << ind2 << " " << max1 << " " << max2 << "\n";
        for (int j = 0; j < rows.size(); j++) {
            if (j != i) {
                int sum = rows[j][ind] + rows[j][ind2];
                currSum = rowSum + sum;
                if (currSum > maxSum) {
                    maxSum = currSum;
                }
            }
        }
    }

    return maxSum;
    
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> rows;
    vector<vector<int>> cols;

    for (int i = 0; i < R; i++) {
        vector<int> r;
        for (int j = 0; j < C; j++) {
            int x;
            cin >> x;
            r.push_back(x);

        }

        rows.push_back(r);

    }

    for (int i = 0; i < C; i++) {
        vector<int> col;
        for (int j = 0; j < R; j++) {
            col.push_back(rows[j][i]);

        }
        cols.push_back(col);
    }

    int sum1 = findMax(rows);
    int sum2 = findMax(cols);

    cout << max(sum1, sum2) << "\n";

}