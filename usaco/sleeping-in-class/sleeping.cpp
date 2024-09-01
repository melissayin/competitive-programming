#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        vector<int> elsielog;
        int sum = 0;
        int numentries;
        cin >> numentries;

        for (int j = 0; j < numentries; j++) {
            int entry;
            cin >> entry;
            elsielog.push_back(entry);
            sum += entry;
        }

        int biggest = 0;
       
        for (int j: elsielog) {
            if (j > biggest) {
                biggest = j;
            }
        }


        if (biggest == 0) {
            cout << 0 << "\n";
            continue;
        }

        int target = 0;
       

        for (int j = biggest; j <= sum; j++) {
            if (sum % j != 0) {
                continue;
            }

            int tempsum = 0;
            bool works = true;
            for (int k = 0; k < elsielog.size(); k++) {
                tempsum += elsielog[k];

                if (tempsum > j) {
                    works = false;
                    continue;
                }

                if (tempsum == j) {
                    tempsum = 0;
                
                }
            }

            if (works) {
                target = j;
                break;
            }

        }

        int num_ending_entries = sum / target; 
        int answer = numentries - num_ending_entries;
        cout << answer << "\n";

    }


}

/*

find sum
find biggest element
test values from biggest to sum 
    see if works as target value for all entries


*/