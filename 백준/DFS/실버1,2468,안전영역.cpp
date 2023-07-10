// 14:30 ~ 15:08

#include <iostream>
using namespace std;

int N;
int table[101][101] = { 0 };
bool land[101][101] = { 0 };

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    land[y][x] = false;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;

        if (land[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> N;
    int highest = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
            highest = max(highest, table[i][j]);
        }
    }

    int maxCount = 1;
    for (int h = 1; h < highest; h++) {
        int count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (table[i][j] > h)
                    land[i][j] = true;
                else
                    land[i][j] = false;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(land[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }

        maxCount = max(maxCount, count);
    }

    cout << maxCount;
}