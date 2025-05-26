#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string text, line, code;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        else {
            text += " ";
        }
        text += line;
        code = line;
    }

    //cout << text << "\n";
    //cout << code << "\n";

    text = text.substr(0, text.size() - code.size());
    // cout << text << "\n";
    vector<vector<vector<string>>> sentenceWords; // with words 
    vector<vector<string>> sentence;
    vector<string> words;
    string currWord = "";

    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalnum(c)) {
            currWord += c;
        }
        else {
            if (!(currWord == "")) {
                words.push_back(currWord);
                currWord = "";
            }
            if (c == '.' || c == '?' || c == '!') {
                if (!words.empty()) {
                    sentence.push_back(words);
                    words.clear();
                }
                if (!sentence.empty()) {
                    sentenceWords.push_back(sentence);
                    sentence.clear();
                }
            
                if (i + 1 < text.size() && text[i + 1] == ' ') {
                    i++;
                }
            }
            
            else if (c == ' ' || !isalnum(c)) {
                if (!words.empty()) {
                    sentence.push_back(words);
                    words.clear();
                }
            } 

        }
        
    }
    /*
    for (auto x: sentenceWords) {
        for (auto y: x){
            for (auto z: y) {
                cout << z << "\n";
            }
            
        }
    }

    */

    vector<string> codes;
    string curr = "";
    for (int i = 0; i < code.size(); i++) {
        if (code[i] == ' ') {
            codes.push_back(curr);
            curr = "";
            continue;
        }
        else {
            curr += code[i];
        }
    }
    if (!curr.empty()) {
        codes.push_back(curr);
    }
    

    string output = "";
    for (int i = 0; i < codes.size(); i++) {
        int s =0, w = 0, c = 0;
        string num1;
        string num2;
        string num3;
        string num = "";
        
        for (char c: codes[i]) {
            if (c != '.') {
                num += c;
            }
            else {
                if (num1 == "") {
                    num1 = num;
                }
                else if (num2 == ""){
                    num2 = num;
                }
                else if (num3 == "") {
                    num3 = num;
                }
                num = "";
            }
            num3 = num;
        }
        
        //cout << num1 << " " << num2 << " " << num3 << "\n";
        s = stoi(num1);
        w = stoi(num2);
        c = stoi(num3);
        //cout << s << " " << w << " " << c << "\n";
        /**/
        if (s > 0 && s <= sentenceWords.size()) {
            auto& currSent = sentenceWords[s - 1];
        
            if (w > 0 && w <= currSent.size()) {
                auto& currWord = currSent[w - 1];
            
                string actualWord = currWord[0];
                //cout << actualWord << "\n";
                if (c > 0 && c <= actualWord.size()) {
                    char a = actualWord[c - 1];
                    //cout << a << " ";
                    output += a;
                }
                else {
                    output += " ";
                }
            }
            else {
                output += " ";
            }
        }
        else {
            output += " ";
        }
        

    }
    cout  << output << "\n";


}

/*
if (s > 0 && s <= sentenceWords.size()) {
            auto sent = sentenceWords[s - 1];
            if (w > 0 && w <= sent.size()) {
                auto word = sent[w - 1];
                if (c > 0 && c <= word.size()) {
                    output += word[c - 1];
                    cout << output << "\n";
                }

            }
        }*/