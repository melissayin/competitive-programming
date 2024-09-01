#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;
   
    for (long long i = 1; i < (n + 1); i++) {
        long long rows = i - 2;
        long long columns = i - 1;
        long long complement = rows * columns * 4;
        long long total = (i * i)* ((i * i) -1) / 2;
        long long answer = total - complement;
        cout << answer << "\n";
    }
    
}