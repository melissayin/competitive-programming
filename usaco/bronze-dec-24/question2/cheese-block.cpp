#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<tuple<int, int, int>> coords;
    
    unordered_map<string, int> xys;
    unordered_map<string, int> xzs;
    unordered_map<string, int> yzs;
    
    int total = 0;
    
    for (int i = 0; i < Q; i++) {
        int blocks = 0;
        int x, y, z;
        cin >> x >> y >> z;
        tuple tup = make_tuple(x, y, z);
        string xy1 ="", xz1 = "", yz1 = "";
        xy1 = to_string(x) + " " + to_string(y);
        xz1 = to_string(x) + " " + to_string(z);
        yz1 = to_string(y) + " " + to_string(z);
        
       //cout << "xy1 = " << xy1 << "\n";
        if (xys.count(xy1) == 0) {
            xys[xy1] = 1;
        } 
        else {
            xys[xy1]++;
        }
       
        if (xys[xy1] == N) {
            total++;
        }

     
        if (xzs.count(xz1) == 0) {
            xzs[xz1] = 1;
        } 
        else {
            xzs[xz1]++;     
        }
        
        if (xzs[xz1] == N) {
            total++;
        }

     
        if (yzs.count(yz1) == 0) {
            yzs[yz1] = 1;
        } 
        else {
            yzs[yz1]++;

        }

        if (yzs[yz1] == N) {
            total++;
        }


        coords.push_back(tup);
        //total += blocks;
        cout << total << "\n";

    }
    

}