#include <bits/stdc++.h>
using namespace std;

/*
1. Iterate through all possible ordered triples (i, j, k)
2. For each triple (i, j, k), we need to test if its sufficient to
    differentiate a spotty and a plain cow
3. If it is, then increment the answer by 1
4. Return answer
*/

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;

    cin >> N >> M;

    vector<string> spotty; 
    vector<string> plain;

    for (int i = 0; i < N; i++) {
        string cow;
        cin >> cow;
        spotty.push_back(cow);

    }

    for (int i = 0; i < N; i++) {
        string cow;
        cin >> cow;
        plain.push_back(cow);

    }


    /*
        Instead of for each spotty cow and for each plain cow -> n^2 checks 

        For each spotty cow, save the substring of genomes somewhere

        Then, for each plain cow, look up to see if its substring of genomes is already
            saved from above


        Solution 1: Hash set


        Solution 2:
    
        A, C, T, G -> [0, 1, 2, 3]

        then, for any combination of three letters, the base 4 representation will be unique
        Example:
         
        TGA -> 230_4 -> 2*16+3*4+0*1 = 44
        
        333 -> 3*16+3*4+3*1 = 63
        
        all triplets of A,C,T,G can be uniquely mapped to a number between 0 and 63
        AAA -> GGG

        spotty_cow_genomes[i] is true if the triplet mapping to the number i has been seen 
        
        then, if you want to check the plain cow genome, you map it to a number j, and then check
        if spotty_cow_genomes[j] is true or false
        */

    int count = 0; 
    for (int i = 0; i < M; i++) { // O(M^3*N^2) -> 50^3*500^2 ~~ 31B operations
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                // check the triple (i, j, k) 
                bool different = true;

                unordered_set<string> spotty_cow_genomes; // hash set
                for (int h = 0; h < N; h++) { // O(N)
                    string spotty_cow = spotty[h];
                    string sgenomes;
                    sgenomes += spotty_cow[i];
                    sgenomes += spotty_cow[j];
                    sgenomes += spotty_cow[k];
                    spotty_cow_genomes.insert(sgenomes); // O(1)
                }
                    
                for (int l = 0; l < N; l++) { // O(N)
                    string plain_cow = plain[l];
                    string pgenomes;
                    pgenomes += plain_cow[i];
                    pgenomes += plain_cow[j];
                    pgenomes += plain_cow[k];

                    if (spotty_cow_genomes.count(pgenomes) != 0) { // O(1)
                        different = false;
                        break;
                    }
                }

                if (different) {
                    count++;
                }
            }
        }
    }

    //cout << count << "\n";
}
