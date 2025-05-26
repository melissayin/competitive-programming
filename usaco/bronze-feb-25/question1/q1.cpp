#include <bits/stdc++.h>
using namespace std;



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, U;
    cin >> N >> U;
    vector<string> canvasRows;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        canvasRows.push_back(row);
    }
    /*
    2 1
    3 4
    */
    vector<string> oneRows;
    vector<string> twoRows;
    vector<string> threeRows;
    vector<string> fourRows;
    for (int i = 0; i < canvasRows.size(); i++) {
        if (i < canvasRows.size() / 2) {
            string q2 = canvasRows[i].substr(0, N/2);
            string q1 = canvasRows[i].substr(N/2);
            oneRows.push_back(q1);
            twoRows.push_back(q2);
        }
        else {
            string q3 = canvasRows[i].substr(0, N/2);
            string q4 = canvasRows[i].substr(N/2);
            threeRows.push_back(q3);
            fourRows.push_back(q4);

        }
        
    }

    // converted to quadrant 1
    vector<tuple<int, int>> changes;
    for (int i = 0; i < U; i++) {
        int r, c;
        cin >> r >> c;


    }


}