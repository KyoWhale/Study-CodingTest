// 21:49 ~ 
#include <iostream>
#include <queue>
using namespace std;
int table[2501][2501];
bool visited[2501][2501];
int T, N, M, K;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int Y, int X) {
    queue<pair<int, int> > q;
    q.push({Y, X});
    visited[Y][X] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second; q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 > nx || M <= nx || 0 > ny || N <= ny) continue;
            if (table[ny][nx] == 0 || visited[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                table[i][j] = 0;
                visited[i][j] = false;
            }
        }
        for (int k = 0; k < K; k++) {
            int x, y;
            cin >> y >> x;
            table[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++){
                if (table[i][j] == 1 && visited[i][j] == false) {
                    bfs(i, j); cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}