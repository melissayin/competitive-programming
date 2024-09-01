#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> solution(26);

    for (int i = 0; i < n; i++) {
        vector<int> counts1(26);
        vector<int> counts2(26);

        string word1, word2;
        cin >> word1 >> word2;

        for (char j: word1) {
            counts1[j - 'a']++; 
        }

        for (char j: word2) {
            counts2[j - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            solution[j] += max(counts1[j], counts2[j]);

        }

    }

    for (int i: solution) {
        cout << i << "\n";
    }
    
}