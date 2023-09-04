// 16:59 ~ X
#include <iostream>
using namespace std;

int table[100001];
int checked[100001];
int N;

void check(int start) {
    int current = start;
    while (true) {
        checked[current] = start; // 처음 사람 표식
        current = table[current]; // 다음 사람
        if (checked[current] == start) {
            while (checked[current] != -1) {
                checked[current] = -1;
                current = table[current];
            }
            return;
        }
        else if (checked[current] != 0) return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        fill(checked+1, checked+1+N, 0);
        for (int i = 1; i <= N; i++) {
            cin >> table[i];
        }
        
        for (int i = 1; i <= N; i++) {
            if (checked[i] == 0)
                check(i);
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (checked[i] != -1) cnt++;
        }
        cout << cnt << "\n";
    }    
}