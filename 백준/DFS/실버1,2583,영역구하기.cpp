// 16:16 ~ 16:42

#include <iostream>
#include <list>
using namespace std;

int N, M, K;
int paper[101][101];
int areaCount;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    areaCount++;
    paper[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || 0 > ny || nx >= M || ny >= N) continue;

        if (paper[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for (int k = 0 ; k < K; k++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int y = ly; y < ry; y++) {
            for (int x = lx; x < rx; x++) {
                paper[y][x] = 1;
            }
        }
    }

    list<int> area;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (paper[i][j] == 0) {
                dfs(i, j);
                area.push_back(areaCount);
                areaCount = 0;
            }
        }
    }

    area.sort();
    cout << area.size() << "\n";
    while (area.size() > 0) {
        cout << area.front() << " ";
        area.pop_front();
    }
}