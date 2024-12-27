#include <bits/stdc++.h>
using namespace std;

bool canPlaceTile(string tile, string row) {
    char up = row[row.size() - 1];
    return tile[0] == up || tile[1] == up;
}

void placeTile(string &row, string tile) {
    char lastChar = row[row.size() - 1];
    if (tile[0] == lastChar) {
        row += tile[1];
    } else {
        row += tile[0];
    }
}

vector<string> tiles(string tiles) {
    vector<string> result;
    string tile = "";
    for (char c : tiles) {
        if (c != ' ') {
            tile += c;
            if (tile.size() == 2) {
                result.push_back(tile);
                tile = "";
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("tiles.in", "r", stdin);
    freopen("tiles.out", "w", stdout);

    int initial;
    string handTiles, drawTiles;
    cin >> initial;
    cin.ignore();
    getline(cin, handTiles);
    getline(cin, drawTiles);

    vector<string> rows(4);
    for (int i = 3; i >= 0; i--) {
        rows[i] = to_string(initial % 10);
        initial /= 10;
    }

    vector<string> hand = tiles(handTiles);
    vector<string> drawPile = tiles(drawTiles);

    
    
    bool canPlay = true;

    while (canPlay) {
        int currentRow = 0;
        bool placedTile = false;
        bool doubleTile = false;
    
        for (int i = 0; i < hand.size(); i++) {
            bool stop = false;
            for (int row = 0; row < 4; row ++) {
                if (canPlaceTile(hand[i], rows[row])) {
                    placeTile(rows[currentRow], hand[i]);
                    doubleTile = hand[i][0] == hand[i][1];
                    hand.erase(hand.begin() + i);
                    placedTile = true;
                    currentRow = row;
                    stop = true;
                    break;
                }
            }
        
        }

        if (doubleTile) {
            bool placed = false;
            while (!placed) {
                for (int i = 0; i < hand.size(); i++) {
                    if (canPlaceTile(hand[i], rows[currentRow])) {
                        placeTile(rows[currentRow], hand[i]);
                        doubleTile = hand[i][0] == hand[i][1];
                        hand.erase(hand.begin() + i);
                        placed = true;

                        break;
                    }
                }

                if (!placed) {
                    if (!drawPile.empty()) {
                        hand.push_back(drawPile[0]);
                        drawPile.erase(drawPile.begin());
                    } 
                    else {
                        canPlay = false;
                    }
                }   
            }

        }


        if (!placedTile) {
            if (!drawPile.empty()) {
                hand.push_back(drawPile[0]);
                drawPile.erase(drawPile.begin());
            } else {
                canPlay = false;
            }
        }

        int cantPlace = 0;

        for (int i = 0; i < hand.size(); i++) {
            if (!canPlaceTile(hand[i], rows[currentRow])) {
                cantPlace++;
            }
        }

        if (hand.empty() || drawPile.empty() || cantPlace == hand.size()) {
            canPlay = false;
        }
    }

    if (hand.empty()) {
        cout << 0 << "\n";
    } else {
        int sum = 0;
        for (string tile : hand) {
            sum += tile[0] - '0' + tile[1] - '0';
        }
        cout << sum << "\n";
    }
}
