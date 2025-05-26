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
        text += (text.empty() ? "" : " ") + line;
        code = line;
    }

    text = text.substr(0, text.size() - code.size());

    vector<vector<vector<string>>> sentenceWords;
    vector<vector<string>> sentence;
    vector<string> words;
    string currWord;

   
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalnum(c)) {
            currWord += c;
        } 
        else {
            if (!currWord.empty()) {
                words.push_back(currWord);
                currWord.clear();
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
               
                if (i + 2 < text.size() && text[i + 1] == ' ' && text[i + 2] == ' ') {
                    i += 2;
                }
            }
        }
    }

    if (!currWord.empty()) {
        words.push_back(currWord);
    }
    if (!words.empty()) {
        sentence.push_back(words);
    }
    if (!sentence.empty()) {
        sentenceWords.push_back(sentence);
    }

    vector<string> codes;
    string currCode;
    for (char c : code) {
        if (c == ' ') {
            if (!currCode.empty()) {
                codes.push_back(currCode);
            }
            currCode.clear();
        } 
        else {
            currCode += c;
        }
    }
    if (!currCode.empty()) {
        codes.push_back(currCode);
    } 

    string output;

    for (string coded: codes) {
        int s = 0, w = 0, c = 0;
        int dotCount = 0;
        string temp;

        for (char ch : coded) {
            if (ch == '.') {
                if (dotCount == 0){
                    s = stoi(temp);
                } 
                else if (dotCount == 1) {
                    w = stoi(temp);
                }
                temp.clear();
                dotCount++;
            } 
            else {
                temp += ch;
            }
        }
        if (!temp.empty()) c = stoi(temp);

        if (s > 0 && s <= sentenceWords.size()) {
            auto& currSent = sentenceWords[s - 1];

            if (w > 0 && w <= currSent.size()) {
                auto& currWord = currSent[w - 1];

                if (c > 0 && c <= currWord.size()) {
                    output += currWord[c - 1];
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

    cout << output << "\n";

}
