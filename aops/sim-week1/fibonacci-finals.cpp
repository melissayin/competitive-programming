#include <bits/stdc++.h>
using namespace std;

/*
x
y
1x + 1y
1x + 2y
2x + 3y
3x + 5y
5x + 8y
*/
int nums[2];
int a, b, c, d;

void fastDouble(long long n, int r[]) {
    if (n == 0) {
        r[0] = 0;
        r[1] = 1;
        return;
    }

    fastDouble(n / 2, r);

    a = r[0];
    b = r[1];
    c = 2 * b - a;

    if (c < 0) {
        c += 1000;
    }

    c = (a * c) % 1000;

    d = (a * a + b * b) % 1000;

    if (n % 2 == 0) {
        r[0] = c;
        r[1] = d;
    }
    else {
        r[0] = d;
        r[1] = c + d;
    }
    
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long J0, J1, N, K;
    cin >> J0 >> J1 >> N >> K;
    
    int ans = 0;
    fastDouble(N - 1, nums);
    //cout << nums[0] << ' ' << nums[1] << "\n";
    ans += nums[0] * J0;
    ans += nums[1] * J1;

    if (K == 1) {
        cout << ans % 10 << "\n";
    }
    else if (K == 2) {
        cout << ans % 100 << "\n";
    }
    else {
        cout << ans % 1000 << "\n";
    }
    /*
    for (long long i = 0; i < N - 1; i++) {
        curr = prev + prev2;
       // cout << curr << " ";
        prev2 = prev;
        prev = curr;
       
        
        curr = curr % 1000;
        

    }*/

}