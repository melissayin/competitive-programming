#include <bits/stdc++.h>
using namespace std;

void createArrays(string input, vector<char> &letters, vector<int> &values) {
    for (char ch : input) {
        auto it = lower_bound(letters.begin(), letters.end(), ch);
        int index = distance(letters.begin(), it);
        int value = 0;

        if (!letters.empty()) {
            if (index == 0) value = values.front() + 1;
            else if (index == letters.size()) value = values.back() + 1;
            else value = max(values[index - 1], values[index]) + 1;
        }

        letters.insert(it, ch);
        values.insert(values.begin() + index, value);
    }
}

void constructStrings(vector<char> &letters, vector<int> &values, string &asFound, string &other) {
    if (letters.empty()) return;

    vector<bool> visited(letters.size(), false);
    int startIdx = min_element(values.begin(), values.end()) - values.begin();
    int left = startIdx, right = startIdx;

    while (left >= 0 || right < letters.size()) {
        if (left >= 0 && !visited[left]) {
            visited[left] = true;
            asFound += letters[left];
            left--;
        } 
        else if (right < letters.size() && !visited[right]) {
            visited[right] = true;
            asFound += letters[right];
            right++;
        } 
        else {
            break;
        }
    }

    for (int i = letters.size() - 1; i >= 0; i--) {
        if (visited[i]) {
            other += letters[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    cin >> input;
    vector<char> letters;
    vector<int> vals;

    createArrays(input, letters, vals);

    string string1, string2;
    constructStrings(letters, vals, string1, string2);

    cout << string1 << " " << string2 << endl;
  
}
