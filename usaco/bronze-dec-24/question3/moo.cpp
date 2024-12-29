#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   /*
   find current moos + counts

   go through and change a character
   check the 3 moos it changes
        if changes somethign into a moo
        check moo counts + thresholds 
    
        if changes moo into diff moo
        adjust and check moo counts/threshold

   */
    int N, F;
    string moos;
    cin >> N >> F >> moos;

    unordered_map<string, int> og_mooCounts;
    vector<string> possibleMoos;
    unordered_map<string, int> new_mooCounts;
    
    for (int i = 0; i < N - 2; i++) {
        string moo = moos.substr(i, 3);
        if (moo[1] == moo[2] && moo[0] != moo[1]) {
            
        }
        
    }
}