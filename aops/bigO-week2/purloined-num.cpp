#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> nums;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());

    bool solved = false;

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i + 1] - nums[i] > 1) {
            cout << nums[i] + 1 << "\n";
            solved = true;
            break;
        }
    }

    if (!solved) {
        cout << -1 << "\n";
    }

    

}