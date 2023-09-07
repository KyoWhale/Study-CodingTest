// 17:10 ~ 17:28
#include <iostream>
using namespace std;

int N, M;
int used[9];

void dfs(int depth) {
    if (depth == M) {
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (used[j] == i) {
                    cout << j << " ";
                    break;
                }
            }
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (used[i] != 0) continue;
        used[i] = depth+1;
        dfs(depth+1);
        used[i] = 0;
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}