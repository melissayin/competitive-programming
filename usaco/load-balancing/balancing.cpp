#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int N, B;

    cin >> N >> B;

    vector<tuple<int, int>> positions;
    vector<int> ypositions;
    vector<int> q1;
    vector<int> q2;
    vector<int> q3;
    vector<int> q4;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ypositions.push_back(y);
        positions.push_back(make_tuple(x,y));

    }
    
    sort(positions.begin(), positions.end());
    sort(ypositions.begin(), ypositions.end());


    int half1_count = 0;
    int answer = 0;
    int a = 0;

    for (int i = 0; i < positions.size(); i++) {
        half1_count++;
        if (half1_count >= N/2) {
            a = get<0>(positions[i]) + 1;
            break;

        }

    }

   
    int yhalf1 = 0;
   
    int b = 0;
    for (int i = 0; i < ypositions.size(); i++) {  
        yhalf1++;

        if (yhalf1 >= N/2) {
            b = (ypositions[i]) + 1;
            break;

        }

    }

    for (int i = 0; i < positions.size(); i++) {
        int x, y;
        x = get<0>(positions[i]);
        y = get<1>(positions[i]); 

        if (x > a && y > b) {
            q1.push_back(x);
           //cout << "q1:" << x << "\n";
        }
        else if (x < a && y > b) {
            q2.push_back(x);
            //cout << "q2:" << x << "\n";
        }
        else if (x < a && y < b) {
            q3.push_back(x);
            //cout << "q3:" << x << "\n";
        }
        else if (x > a && y < b) {
            q4.push_back(x);
            //cout << "q4:" << x << "\n";
        }

    }

    answer = max(q1.size(), max(q2.size(), max(q3.size(), q4.size())));

    cout << answer << "\n";

}

   

/*
    cut cows in half, find values of each half
    cut each half in half, find values of quarters
    output min of max
*/