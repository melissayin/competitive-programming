#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    int distinct_num = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i + 1] != nums[i]) {
            distinct_num++;
        }
    }

    cout << distinct_num << "\n";

}