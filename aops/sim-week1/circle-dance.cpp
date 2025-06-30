#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int P, R, K;
    cin >> P >> R >> K;
   
    int numCycles = R % P;
    //cout << "ncycles: " << numCycles << "\n";
    long long left = K - 1;
    long long right = K + 1;
    long long add = numCycles * 2;
    if (K & 2 == 1) {
        left += add;
        right += add;
    }
    else {
        left -= add;
        right -= add;
    }
    left = left % P;
    right = right % P;

    while (left <= 0) {
        left += P;
    }

    while (right <= 0) {
        right += P;
    }
    
    cout << left << " " << right << "\n";
   

    /*
    long long L = K - 1;
    long long right = K + 1;
    if (L == 0) {
        L = P;
    }
    if (right == P + 1) {
        right = 1;
    }
    //cout << "L:" << L << "\n";
    if (increasing) {
        for (int i = 0; i < numCycles; i++) {
            L += 2;
            if (L > P) {
                L -= P;
            }
            right += 2;
            if (right > P) {
                right -= P;
            }
        }
         //cout << "L:" << L << "\n";
    }
    else {
        for (int i = 0; i < numCycles; i++) {
            L -= 2;
            if (L <= 0) {
                L += P;
            }
            right -= 2;
            if (right <= 0) {
                right += P;
            }
        }

       
        //cout << "L:" << L << "\n";
    }
    L = L % (P);
    if (L == 0) {
        L = P;
    }
    //cout << "L:" << L << "\n";
    right = right % P;
    if (right == 0) {
        right = P;
    }




    for (int i = 1; i <= P; i++) {
        if (i % 2 == 1) {
            for (int j = 0; j < cows.size() - 1; j+=2 ) {
                int temp = cows[j];
                cows[j] = cows[j + 1];
                cows[j + 1] = temp;
            }
        }
        else {
            int temp = cows[0];
            cows[0] = cows[cows.size() - 1];
            cows[cows.size() - 1] = temp;
            for (int j = 1; j < cows.size() - 2; j+= 2) {
                int temp = cows[j];
                cows[j] = cows[j + 1];
                cows[j + 1] = temp;
            }

        }



        
        for (int x: cows) {
            cout << x << " ";
        }
        cout << "\n";
        
        
        
    }



    for (int i = 0; i < cows.size(); i++) {
        if (cows[i] == K) {
            if (i != 0 && i != cows.size() - 1) {
                cout << cows[i - 1] << " " << cows[i + 1] << "\n";
            }
            else if (i == 0) {
                cout << cows[cows.size() - 1] << " " << cows[1] << "\n";
            }
            else if (i == cows.size() - 1) {
                cout << cows[cows.size() - 2] << " " << cows[0] << "\n";
            }
        }
    }
        */
        

}