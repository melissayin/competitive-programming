#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string text, line, input;

    while (getline(cin, line)) {
        if (line.empty()) break;
        text += (text.empty() ? "" : " ") + line;
    }

   
    getline(cin, input);

   
    vector<vector<vector<string>>> sentences; 
    vector<vector<string>> currentSentence;
    vector<string> currentWords;
    string currentWord;

    for (int i = 0; i < text.size(); ++i) {
        char c = text[i];
        if (isalnum(c)) {
            currentWord += c;
        } else {
            if (!currentWord.empty()) {
                currentWords.push_back(currentWord);
                currentWord.clear();
            }
            if (c == '.' || c == '?' || c == '!') {
                if (!currentWords.empty()) {
                    currentSentence.push_back(currentWords);
                    currentWords.clear();
                }
                if (!currentSentence.empty()) {
                    sentences.push_back(currentSentence);
                    currentSentence.clear();
                }
                if (i + 2 < text.size() && text[i + 1] == ' ' && text[i + 2] == ' ') {
                    i += 2; 
                }
            }
        }
    }
    if (!currentWord.empty()) {
        currentWords.push_back(currentWord);
    }
    if (!currentWords.empty()) {
        currentSentence.push_back(currentWords);
    }
    if (!currentSentence.empty()) {
        sentences.push_back(currentSentence);
    }


    unordered_map<char, vector<tuple<int, int, int>>> charPositions;
    for (size_t s = 0; s < sentences.size(); ++s) {
        for (size_t w = 0; w < sentences[s].size(); ++w) {
            for (size_t c = 0; c < sentences[s][w].size(); ++c) {
                char ch = sentences[s][w][c][0];
                charPositions[ch].emplace_back(s + 1, w + 1, c + 1);
            }
        }
    }

   
    string encodedMessage;
    for (size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];
        if (isalnum(ch)) {
            int occ = i + 1;
            auto &positions = charPositions[ch];
            while (occ > positions.size()) {
                occ /= 2; 
            }
            auto [s, w, c] = positions[occ - 1];
            encodedMessage += to_string(s) + "." + to_string(w) + "." + to_string(c) + " ";
        } 
        else if (ch == ' ') {
            encodedMessage += "_ ";
        } 
        else {
            encodedMessage += ch; 
        }
    }

  
    cout << encodedMessage << "\n";

}
