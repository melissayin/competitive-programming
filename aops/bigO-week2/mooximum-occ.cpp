#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    int numA = stoi(a);
    int numB = stoi(b);
    if (numA != numB) return numA < numB;
    return a.back() < b.back();
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> enters;
    vector<string> exits; 
    set<int> timesSet;
    vector<string> times;

    for (int i = 0; i < N; i ++) {
        int x;
        cin >> x;
        //enters.push_back(to_string(x) + "E");
        times.push_back(to_string(x) + "E");
        
       // timesSet.insert(x);

    }
    for (int i = 0; i < N; i ++) {
        int x;
        cin >> x;
        //exits.push_back(to_string(x) + "L");
        times.push_back(to_string(x) + "L");
        
       // timesSet.insert(x);

    }

    
    sort(times.begin(), times.end(), compare);
   

    int curr = 0;
    int maxCows = 0;
    for (string x: times) {
        if (x.substr(x.size() - 1) == "E") {
            curr++;
            if (curr > maxCows) {
                maxCows = curr;
            }
        }
        else {
            curr--;
            if (curr < 0) {
                curr = 0;
            }
        }

        if (curr > maxCows) {
            maxCows = curr;
        }
    }

    cout << maxCows << "\n";


}