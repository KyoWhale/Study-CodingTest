// 15:50 ~ 16:02

#include <iostream>
#include <memory.h>
using namespace std;

int w, h;
int map[51][51] = { 0 };

int dx[] = {1, 0, -1 , 0, 1, 1, -1, -1};
int dy[] = {0, 1 , 0, -1, -1, 1, -1, 1};

void dfs(int y, int x) {
    map[y][x] = 0;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || 0 > ny || w <= nx || h <= ny) continue;

        if (map[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}

int main() {
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1) {
                    dfs(i, j);
                    count++;
                }
            }
        }

        memset(map, 0, sizeof(map));
        cout << count << "\n";
    }
}