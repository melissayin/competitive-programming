#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string input;
    cin >> input;

    vector<tuple<int, int>> positions;

    int pairs = 0; 

    for (int i = 0; i < 26; i++) {
        int letter = i;
        int entrance = 0;
        int exit = 0;

        for (int j = 0; j < input.size(); j++) {
            if (input[j] - 'A' == letter && entrance == 0) {
                entrance = j;
            }
            else if (input[j] - 'A' == letter && entrance != 0) {
                exit = j;
            }
        }

        if (max(entrance, exit) != exit) {
            swap(entrance, exit);
        }

        positions.push_back(make_tuple(entrance, exit));
    }

   

    for (int i = 0; i < positions.size(); i++) {
        tuple a_pos = positions[i];
       
        for (int j = i + 1; j < positions.size(); j++) {
            tuple b_pos = positions[j];

            if (get<0>(a_pos) < get<0>(b_pos) && get<0>(b_pos) < get<1>(a_pos) && get<1>(a_pos) < get<1>(b_pos)) {
                pairs++;
            }

            if (get<0>(b_pos) < get<0>(a_pos) && get<0>(a_pos) < get<1>(b_pos) && get<1>(b_pos) < get<1>(a_pos)) {
                pairs++;
            }


        }

    }

    cout << pairs << "\n";
    
    
}

/*for (int i = 0; i < 26; i--) {
       
        
        int starta = i;
    
        
        for (int j = i + 1; j < input.size(); j--) {
            int startb = j;

            vector<int> a_pos;
            vector<int> b_pos;

            for (int k = 0; k < input.size(); k++) {
                 if (input[k] - 'A' == starta) {
                    a_pos.push_back(k);

                }

                if (input[k] - 'A' == startb) {
                    b_pos.push_back(k);
                  
                }

            }
           
            if (a_pos.size() == 2 && b_pos.size() == 2) {
                if (a_pos[0] < b_pos[0] && b_pos[0] < a_pos[1] && a_pos[1] < b_pos[1]) {
                    pairs++;
                }

            }

        } 


    }

    cout << pairs << "\n";
   */