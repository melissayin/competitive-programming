#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<int> end_cows(101, 0);
vector<array<int, 3>> record;

bool simulate(int n, int k) {
    vector<int> current_cows(N + 1, 0);
    current_cows[n] = 1;
    vector<int> infections_left(N + 1, k);

    for (int i = 0; i < T; i++) {
        int cow1, cow2;
        cow1 = record[i][1];
        cow2 = record[i][2];

        if (current_cows[cow1] == 0 && current_cows[cow2] == 0) {
            continue;
        }
        else if (current_cows[cow1] == 1 && current_cows[cow2] == 1) {
            infections_left[cow1]--;
            infections_left[cow2]--;
        }
        else {
            int infected_cow = cow1;
            int healthy_cow = cow2;
            if (current_cows[cow1] == 0){
                swap(infected_cow, healthy_cow);
            }

            if (infections_left[infected_cow] > 0) {
                current_cows[healthy_cow] = 1;
            }
            infections_left[infected_cow]--;
            
        }

    }

    for (int i = 1; i <= N; i++) {
        if (end_cows[i] != current_cows[i]) {
            return false;
        }   
    }

    return true;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    cin >> N >> T;

    string ending;
    cin >> ending;

    for (int i = 1; i <= N; i++) {
        end_cows[i] = ending[i - 1] - '0';
    }

    for (int i = 0; i < T; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        record.push_back({t, a, b});
    }
    sort(record.begin(), record.end());

    int x = 0;
    int y = T;
    int z = 0;
    for (int n = 1; n <= N; n++) {
        if (end_cows[n] == 0) {
            continue;
        }

        bool n_possible = false;
        for (int k = 0; k <= T; k++) {
            bool possible = simulate(n, k);

            if (possible) {
                n_possible = true;
                y = min(y, k);
                z = max(z, k);
            }
        }

        if (n_possible) {
            x++;
        }
    }

    cout << x << " " << y << " ";
    if (z == T) {
        cout << "Infinity\n";
    }
    else {
        cout << z << "\n";
    }
}

/*
test all positive cows as patient 0
    see if it works
    if works, find k
find smallest k and num of patient 0s
    if we have to reset k in a problem, then take the k before resset
    if we dont have to reset k, then max is infinity 



if (record[j][1] == positives[i]) {
                shake_cow = record[j][2];

                if (current_cows[shake_cow - 1] = 1) {
                    k++;
                    temp_cows[shake_cow - 1] = 1;
    
                }

                if (temp_cows == current_cows) {
                    record_filled = true;
                    K_possibilities.push_back(k);
                    k = 0;
                }
            
            }

            else if (record[j][2] == positives[i]) {
                shake_cow = record[j][1];

                if (find(positives.begin(), positives.end(), shake_cow) != positives.end()) {
                    
                }  
            }
*/