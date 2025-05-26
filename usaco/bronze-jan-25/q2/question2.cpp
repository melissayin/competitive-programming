#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N;
    cin >> N;

    unordered_set<int> nums;
    unordered_set<int> mults;
    unordered_map<int, int> multInd;
    unordered_map<int, int> numInd;
    unordered_map<int, int> numOcc;
    
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        
        int temp = nums.size();
        nums.insert(val);
        if (nums.size() != temp) {
            numInd[val] = i;
        }
        if (numOcc.count(val) == 0) {
            numOcc[val] = 1;
        }
        else {
            mults.insert(val);
        }

    }
   // cout  << nums.size() << "\n";
    //cout << mults.size() << "\n";
    cout << (nums.size() - 1)*(mults.size()) << "\n";

}