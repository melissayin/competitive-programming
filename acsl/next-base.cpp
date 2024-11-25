#include <bits/stdc++.h>
using namespace std;

int baseToDecimal(string num, int base) {
    int decimal = 0;
    int p = num.size() - 1;

    for (char dig: num) {
        int digit;
        if (isdigit(dig)) {
            digit = dig - '0';
        }
        else {
            digit = dig - 'A' + 10;
        }
    
        decimal += digit * pow(base, p);
        p--;
    }
    return decimal;
}

string toBase(int num, int base) {
    string result;
    while (num > 0) {
        int digit = num % base;
        if (digit < 10) {
            result += digit + '0';
        }
        else {
            result += digit + 'A' - 10;
        }
        num /= base;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int findModeCount(int num, int base, string start) {
    int newStart = baseToDecimal(start, base);
    vector<string> numbers;
    for (int i = 0; i < num; i++) {
        numbers.push_back(toBase(newStart + i, base));
    }

    unordered_map<char, int> frequency;
    for (string n: numbers) {
        for (char digit: n){
            frequency[digit]++;
        }
    }

    int max = 0;
    for (auto &x: frequency) {
        if (x.second > max) {
            max = x.second;
        }
    }

    return max;

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, b;
    string s;
    cin >> n >> b >> s;

    cout << findModeCount(n, b, s) << "\n";
    
    
}