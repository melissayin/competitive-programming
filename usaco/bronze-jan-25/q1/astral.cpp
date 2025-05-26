#include <bits/stdc++.h>
using namespace std;

int checkStarGroup(string group) {
    int minStars = 0;
    bool hasend = false;
    string end = "";
    if (group == "B") {
        return -1;
    }
    else if (group == "G") {
        return 1;
    }
    else if (group.size() % 2 != 0 && group.size() > 1) {
        hasend = true;
        end = group.substr(group.size() - 2, 1);
        group = group.substr(0, group.size() - 1);
    }
    //cout << "end: " << end << "\n";
    //cout << "group: " << group << "\n";
    
    for (int i = 0; i < group.size() - 1; i+= 2) {
        string starpair = "";
        starpair += group[i];
        starpair += group[i + 1];
        //cout << "starpair " << starpair;
        if (starpair == "GG" || starpair == "GB") {
            //cout << "matched";
            minStars++;
        }
        else if (starpair == "BB" || starpair == "BG") {
            minStars += 2;
        }
    }
    if (hasend) {
        //cout << "got in";
        minStars++;
    }
    return minStars;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, A, B;
        cin >> N >> A >> B;
        //lwhether star has been acc for
        unordered_set<string> accounted;
        vector<string> stars;
        for (int j = 0; j < N; j++) {
            string row;
            cin >> row;
            stars.push_back(row);
            //cout << "row: ";
            //cout << row << "\n";
        }
        
        int count = 0;
        bool impossible = false;
        for (int j = 0; j < N; j ++) {
            for (int k = 0; k < N; k++) {
                char c = stars[j][k];
               
                if (c == 'W') {
                    continue;
                }
            
                else if (c == 'B' || c == 'G') {
                    int temp = accounted.size();
                    accounted.insert(c + to_string(j) + to_string(k));

                    //for (string str: accounted) {
                       // cout << str << " ";
                    //}
                    //cout << "\n";
                    if (accounted.size() != temp) {
                    
                        //cout << "got here";
                        
                        string currgroup = "";
                        currgroup += c;
                        int currj = j;
                        int currk = k;
                        //cout << "added: " << c + to_string(j) + to_string(k);
                        //sky[c + to_string(j) + to_string(k)] = true;
                        bool keepGoing = true;
                        while (keepGoing) {
                            
                            if (currj + B < N && currk + A < N) {
                                //cout << "made it into ";
                                char otherStar = stars[currj + B][currk + A];

                                if (otherStar != 'W' ){
                                    
                                    accounted.insert(otherStar + to_string(currj + B) + to_string(currk + A));
                                    //cout << "then added: " << otherStar + to_string(currj + B) + to_string(currk + A);
                                    currgroup += otherStar;
                                }
                                else {
                                    break;
                                }
                                currj += B;
                                currk += A;
                            }
                            else {
                                break;
                            }
                            
                            
                        }
                        //cout << "grup: ";
                        //cout << currgroup << "\n";
                        if (checkStarGroup(currgroup) == -1) {
                            impossible = true;
                            break;
                        }
                        else {
                            count += checkStarGroup(currgroup);

                        }
                       
                        //cout << "count: " <<  count << "\n";
                        
                    }

            }
            else {
                continue;
            }
            
            
            
        }
        
       
        }
        if (impossible) {
            cout << -1 << "\n";
        }
        else {
            cout << count << "\n";

        }
    

    }
    

}