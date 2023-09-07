// 18:24 ~ 18:32
#include <iostream>
using namespace std;

int N, M;
int used[9];
int arr[9];

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (depth > 0 && arr[depth-1] > i) continue;
        if (used[i] != 0) continue;
        used[i] = 1;
        arr[depth] = i+1;
        dfs(depth+1);
        used[i] = 0;
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}