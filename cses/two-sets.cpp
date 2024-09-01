#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << "NO\n";
    
    }
    else {
        cout << "YES\n";

        vector<int> set1;
        long long sum1 = 0;
        while (sum1 + n < sum / 2) {
            set1.push_back(n);
            sum1 += n;
            n--;

        } 
        long long x = sum / 2 - sum1;
        set1.push_back(x);

        cout << set1.size() << "\n";
        for (int i = 0; i < set1.size(); i++) {
            cout << set1[i] << " ";
        }
        cout << "\n";

        vector<int> set2;
        for (int a = 1; a < n + 1; a++) {
            if (a != x) {
                set2.push_back(a);
            }
        }

        cout << set2.size() << "\n";
        for (int y = 0; y < set2.size(); y++) {
            cout << set2[y] << " "; 
        }
        cout << "\n";
    }
}