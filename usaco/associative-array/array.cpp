#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;

    map<unsigned long long, unsigned long long> nums; 

    for (int i = 0; i < Q; i++) {
        unsigned long long a, b, c;
        cin >> a;
        
        if (a == 0) {
            cin >> b >> c;
            nums[b] = c;

        }
        else {
            cin >> b;
            if (nums.count(b) == 0) {
                cout << 0 << "\n";
            }
            else {
                cout << nums[b] << "\n";

            }
        
        }
    }
    
}