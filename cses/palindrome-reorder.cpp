#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    cin >> input;
    int length = input.size();
  
    vector<int> letter_ct(26, 0);
    for (char i : input) {
        letter_ct[i - 'A']++;
    }

    int odd_ct = 0;

    for (int i: letter_ct) {        
        if (i % 2 == 1) {
            odd_ct++;
        }
    }

    if (odd_ct > 1) {
        cout << "NO SOLUTION\n";
    }
    else {
        vector<char> solution(length);

        char odd;
        int j = 0;
        for (int i = 0; i < letter_ct.size(); i++) {
            for (int n = 0; n < (letter_ct[i]  / 2); n++) {
                    solution[j] = i + 'A';
                    solution[length - 1 - j] = i + 'A';
                    j += 1;
                }
            if (letter_ct[i] % 2 == 1) {
                solution[length / 2] = i + 'A';
            }

        }

        for (char i : solution) {
            cout << i;
        }
       
        cout << "\n";

    }
}