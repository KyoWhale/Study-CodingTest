// 17:38 ~ 17:50 X
#include <iostream>
using namespace std;

int N;
int answer = 0;
bool used1[40];
bool used2[40];
bool used3[40];

void dfs(int y) {
    if (y == N) {
        answer++;
        return;
    }

    for (int x = 0; x < N; x++) {
        if (used1[x] || used2[x+y] || used3[y-x+N-1])
            continue;
        used1[x] = true;
        used2[x+y] = true;
        used3[y-x+N-1] = true;
        dfs(y+1);
        used1[x] = false;
        used2[x+y] = false;
        used3[y-x+N-1] = false;
    }
}

int main() {
    cin >> N;
    dfs(0);
    cout << answer;
}