#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    /* 
    read in n
    make milk amounts for each cow
    reorder cow measurements by day taken (earliest first)
    for each measurement:
        update the milk amount for the cow that's being measured
        if it is greater than the other cows, make it the current picture
        if it is different than the previous picture, add one to count 
    output count
    */

    int n; cin >> n;
    vector<tuple<int, string, int>> measurements;
    
    map<string, int> outputs;
    vector<string> names({"Bessie", "Elsie", "Mildred"});
    for (string cow: names) {
        outputs[cow] = 7;
    }

    for (int i = 0; i < n; i++) {
        int day;
        string cow;
        int change;
        cin >> day >> cow >> change;
        measurements.push_back(make_tuple(day, cow, change));
    }
    // Time Complexity — if n is the size of the list, then sorting takes O(n log n) time
    sort(measurements.begin(), measurements.end()); 
    int changes;
    
    vector<string> old_picture = names;
    for (tuple<int, string, int> measurement: measurements) {
        string cow = get<1>(measurement); 
        outputs[cow] += get<2>(measurement);

        vector<string> new_picture;
        int maximum = max(outputs["Bessie"], max(outputs["Elsie"], outputs["Mildred"]));
        
        for (string name: names) {
            if (outputs[name] == maximum) {
                new_picture.push_back(name);
            }
        }


        if (old_picture != new_picture) {
            changes++;
        }
        
        old_picture = new_picture;
    }

    cout << changes << "\n";

}


