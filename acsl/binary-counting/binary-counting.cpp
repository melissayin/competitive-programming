#include <bits/stdc++.h>
using namespace std;

string toBinary(int num) {
    string result;
    while (num > 0) {
        int digit = num % 2;
        result += digit + '0';
        num /= 2;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

string toBinary8(int num) {
    string result;
    while (num > 0) {
        int digit = num % 2;
        result += digit + '0';
        num /= 2;
    }

    if (result.size() != 8) {
        while (result.size() < 8) {
            result += "0";
        }
    }

    std::reverse(result.begin(), result.end());
    return result;
}

vector<int> findInds(string s, string sub) {
    vector<int> indexes; 
    for (int j = 0; j < s.size() - sub.size() + 1; j++) {
        string check = s.substr(j, sub.size());
        if (check == sub) {
            indexes.push_back(j);
        }
    }

    return indexes;
}

string eraseTwo(vector<int> indexes, string s, string sub) {
    if (indexes.size() < 2) {
        return s;
    }
    s.erase(indexes[indexes.size() - 1], sub.size());
    s.erase(indexes[0], sub.size());
    
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    getline(cin, input);

    string binary = "";
    for (char i: input) {
        int ascii = 0;
        if (i == ' ') {
            ascii = 32;
            
        }
        else {
            ascii = i;
        }
        binary += toBinary8(ascii);
        
    }

    int currDec = 0;
    string currBinary = "0";
    
    bool canRemove = true;
    
    while (canRemove) {
        vector<int> inds = findInds(binary, currBinary);
        if (inds.size() == 0) {
            canRemove = false;
            break;
        }
        
        if (inds[inds.size() - 1] - inds[0] < currBinary.size() || inds.size() == 1) {
            binary.erase(inds[0], currBinary.size());
            currDec++;
            currBinary = toBinary(currDec);
        } 
        else {
            binary = eraseTwo(inds, binary, currBinary);
            currDec++;
            currBinary = toBinary(currDec);
        }
    }
   
    cout << currDec - 1 << "\n";

}
