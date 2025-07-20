#include <bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>> rows) {
    int maxSum = 0;
    // loop all pairs of cols and find sum 
    for (int i = 0; i < rows[i].size(); i++) {
        for (int j = i + 1; j < rows[j].size(); j++) {
            int numRows = rows.size();

            vector<pair<int, int>> rowSums;
            int max1 = -1;
            int max2 = -1;

            for (int k = 0; k < numRows; k++) {
                int sum = rows[k][j] + rows[k][i];
                rowSums.push_back(make_pair(sum, k));
            }

            sort(rowSums.rbegin(), rowSums.rend()); 

            for (int a = 0; a < rowSums.size(); ++a) {
                for (int b = a + 1; b < rowSums.size(); ++b) {
                    if (rowSums[a].second != rowSums[b].second) {
                        int currSum = rowSums[a].first + rowSums[b].first;
                        maxSum = max(maxSum, currSum);
                        break;
                    }
                }
                //break; 
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
    for (int i = 0; i < R; i++) {
        vector<int> r;
        for (int j = 0; j < C; j++) {
            int x;
            cin >> x;
            r.push_back(x);

        }

        rows.push_back(r);

    }

    cout << findMax(rows) << "\n";



}