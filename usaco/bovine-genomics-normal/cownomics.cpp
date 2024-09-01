#include <bits/stdc++.h>
using namespace std;

bool contains (char k, vector<char> list) {
    for (char i: list) {
        if (i == k) {
            return true;
        }
    
    }

    return false;

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<string> spotty;
    vector<string> plain;

    for (int i = 0; i < N; i++) {
        string genome;
        cin >> genome;
        spotty.push_back(genome);
    }


    for (int i = 0; i < N; i++) {
        string genome;
        cin >> genome;
        plain.push_back(genome);
    }

    int count = 0;
    bool indicate = true;

    for (int i = 0; i < M; i++) {
        vector<char> spot_place;
        vector<char> plain_place;
        
        for (int j = 0; j < N; j++) {
            spot_place.push_back(spotty[j][i]);
            plain_place.push_back(plain[j][i]);
            
        }
        for (char k: spot_place) {
                if (contains(k, plain_place) == true) {
                    indicate = false;
                    break; 
                }
                else {
                    indicate = true;
                }
                
        }

        if (indicate == true) {
                count++;
        }

    }

    cout << count << "\n";
   
}