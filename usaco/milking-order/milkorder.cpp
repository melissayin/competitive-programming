#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> milk_order(N + 1);
    unordered_set<int> ordered;

    vector<int> status_order;
    unordered_set<int> status_order_set;
    for (int i = 0; i < M; i++) {
        int cow;
        cin >> cow;
        status_order.push_back(cow);
        status_order_set.insert(cow);
    }

    for (int i = 0; i < K; i++) {
        int pos;
        int cow;
        cin >> cow >> pos;
        if (cow == 1) {
            cout << pos << "\n";
        }
        milk_order[pos] = cow;
        ordered.insert(cow);
    }

    if (status_order_set.count(1) == 1) {
        int in_front = 0;
        for (int i: status_order) {
            if (i != 1) {
                in_front++;
            }
        }
        in_front--;

        for (int i = 1; i < milk_order.size(); i++) {
            if (in_front == 0 && milk_order[i] == 0) {
                cout << i << "\n";
                break;
            }
            if (milk_order[i] == 0) {
                in_front--;
            }
            
        }
        
    }

    vector<int> both;
    for (int cow: status_order) {
        if (ordered.count(cow) == 1) {
            both.push_back(cow);
        }
    }

    

}