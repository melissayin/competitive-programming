#include <bits/stdc++.h>
using namespace std;
string toBaseThree(int num, int length) {
    string ans = "";
    while (num > 0) {
        ans = to_string(num % 3) + ans;
        num /= 3;
    }

    while (ans.size() < length) {
        ans = "0" + ans;
    }

    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string S;
    cin >> N >> S;
    string newS = "";

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'C') {
            newS += "0";
        }
        else if (S[i] == 'O') {
            newS += "1";
        }
        else {
            newS += "2";
        }
    }

    //cout << newS << "\n";
    int count = 0;
    
    for (int i = 0; i < pow(3, N); i++) {
        string cow = toBaseThree(i, N);
        
       
        if (cow.find(newS) == string::npos) {
            //cout << cow << " " << "good" << "\n";
            count++;
        }
    }
    //cout << "\n";

    cout << count << "\n";





}