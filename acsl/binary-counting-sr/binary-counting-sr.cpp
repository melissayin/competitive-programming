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
string toOctal(int num) {
    string result;
    while (num > 0) {
        int digit = num % 8;
        result += digit + '0';
        num /= 8;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

string binToOctal(string bin) {
    string octal = "";
    while (bin.size() % 3 != 0) {
         bin = "0" + bin; 
    }

    for (int i = 0; i < bin.size(); i += 3) {
        string digit = "";
        digit += bin[i];
        digit += bin[i + 1];
        digit += bin[i + 2];

        int ind = 0;
        int octDig = 0;
        for (int j = 2; j >= 0; j--) {
            if (digit[ind] == '1' ) {
                octDig += pow(2, j);
            }
            ind++;
        }
        octal += to_string(octDig);
    }

    return octal;
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

int eraseOctal(string input) {
    int currDec = 0;
    string currOctal = "0";
    
    bool canRemove = true;
    
    while (canRemove) {
        vector<int> inds = findInds(input, currOctal);
        if (inds.size() == 0) {
            canRemove = false;
            currDec--;
            break;
        }
        
        else if (inds[inds.size() - 1] - inds[0] < currOctal.size() || inds.size() == 1) {
            input.erase(inds[0], currOctal.size());
            //cout << input << " ";
            //cout << "currDec: " << currDec << " currOct: " << currOctal << "\n";
            currDec++;
            currOctal = toOctal(currDec);
        } 
        else {
            input = eraseTwo(inds, input, currOctal);
            //cout << input << " ";
            //cout << "currDec: " << currDec << " currOct: " << currOctal << "\n";
            currDec++;
            currOctal = toOctal(currDec);
        }
    }


    return currDec;  
}

string eraseBinary(string input) {
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

     binary.erase(0, binary.find_first_not_of('0'));

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
  
    binary.erase(0, binary.find_first_not_of('0'));
    return binary;  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    getline(cin, input);

    string endBin = eraseBinary(input);
    //cout << endBin << "\n";
    string bin = endBin; 
    string octal = "";
    //cout << binToOctal(endBin) << "\n";
    octal = binToOctal(endBin);
    cout << eraseOctal(octal) << "\n";

   // cout << endBinInt << "\n";
     

}