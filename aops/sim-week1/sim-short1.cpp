#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> paper = {4, 5, 2};
    
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int x: paper) {
            sum += x;
        }
         
        int avg = sum / 3; 
        paper.push_back(avg);
        int smallest = paper[0];
        int smallIndex = 0;
        for (int j = 0; j < paper.size(); j++) {
            if (paper[j] < smallest) {
                smallest = paper[j];
                smallIndex = j;
            }
        }
        paper.erase(paper.begin() + smallIndex);
        for (int x: paper) {
            cout << x << " ";
        }
        cout << "\n";
    }
}