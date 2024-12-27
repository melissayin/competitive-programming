#include <bits/stdc++.h>
using namespace std;

int round(int a, int b) {
    int power = pow(10, b);
    int digit = (a / (power / 10)) % 10;
    
    if (digit >= 5) {
        a += power;
    }
    
    return (a / power) * power;
}
/*
int round(int a, int b) {
    string num = to_string(a);
    string x = "";
    x += num[num.size() - b];
  
    int xInt = stoi(x);
    if (xInt >= 5) {
        a += pow(10, b);
    }

    num = to_string(a);
   
    for (int i = num.size() - b; i < num.size(); i++) {
        num[i] = '0';
    }
    int rounded = stoi(num);
    return rounded; 
}
*/

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        int count = 0;
        
        for (int j = 2; j <= N; j++) {
            if (to_string(j)[0] != '4') {
                continue;
            }

            int rounded;
            int chained = j;
            int P = 0; 
            while (pow(10, P) < j) {
                P++;
            }

            rounded = round(j, P);
           
            bool diff = false;
            for (int k = 1; k <= P; k++) {
                chained = round(chained, k);
                //if (chained / 100 != rounded / 10) {
                    //diff = true;
                    //break;
                //}
            }

            if (rounded != chained || diff) {
                //cout << j << " " << rounded << " " << chained << " " << P << "\n";
                count++;
            }
            

        }

        cout << count << "\n";
    }

    
}
/*
    count how many integers x >= 2 to N exist such that 
    rounding to nearest 10^P is diff than chain rounding
    P = smallest int that 10^P >= x

    find p for each num
    find rounded
    find chain rounded
    compare 
    increment count 
    */

