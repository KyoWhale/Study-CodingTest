// 17:28 ~ 18:02

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> dna_list;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        dna_list.push_back(s);
    }

    string ans_dna;
    int ans_diff = M * M;

    int diffs[51][26] = {0};
    for (int m = 0; m < M; m++) {
        for (int i = 0; i < N; i++) {
            diffs[m][dna_list[i][m] - 'A']++;
        }
    }

    int diff = 0;
    string answer;
    for (int m = 0; m < M; m++) {
        int curMax = 0;
        int curChr = 0;
        for (int a = 0; a < 26; a++) {
            if (diffs[m][a] > curMax) {
                curMax = diffs[m][a];
                curChr = 'A' + a;
            }
        }

        diff += N - curMax;
        answer += curChr;
    }

    cout << answer << "\n";
    cout << diff;
}
