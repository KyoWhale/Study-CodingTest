// 16:09 ~ 17:18
#include <iostream>
#include <queue>
using namespace std;

int T, h, w;
string maps[1001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solution() {
    queue<pair<int, int> > fire;
    queue<pair<int, int> > nfire;
    queue<pair<int, int> > q;
    queue<pair<int, int> > nq;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maps[i][j] == '.' || maps[i][j] == '#') {
                continue;
            }
            if (maps[i][j] == '*') {
                fire.push({i, j});
                continue;
            }
            if (maps[i][j] == '@') {
                q.push({i, j});
            }
        }
    }

    int cnt = 1;
    while (!q.empty()) {
        while(!fire.empty()) {
            auto[fy, fx] = fire.front(); fire.pop();
            for (int d = 0; d < 4; d++) {
                int nfy = fy + dy[d];
                int nfx = fx + dx[d];
                if (nfy >= h || nfx >= w || nfy < 0 || nfx < 0) continue;
                if (maps[nfy][nfx] == '.' || maps[nfy][nfx] =='@') {
                    maps[nfy][nfx] = '*';
                    nfire.push({nfy, nfx});
                }
            }
        }

        while (!q.empty()) {
            auto[y, x] = q.front(); q.pop();
            if (y == 0 || x == 0 || y == h-1 || x == w-1)
                return cnt;
                
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny >= h || nx >= w || ny < 0 || nx < 0) continue;
                if (maps[ny][nx] != '.') continue;
                if (ny == 0 || nx == 0 || ny == h-1 || nx == w-1)
                    return cnt+1;
                maps[ny][nx] = '@';
                nq.push({ny, nx});
            }
        }

        while(!nfire.empty()) {
            fire.push(nfire.front()); nfire.pop();
        }
        while(!nq.empty()) {
            q.push(nq.front()); nq.pop();
        }
        cnt++;
    }

    return -1;
}

int main() {
    cin >> T;
    while (T > 0) {
        cin >> w >> h;
        for (int i = 0; i < h; i++)
            cin >> maps[i];
        int answer = solution();
        if (answer == -1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << answer << "\n";
        }
        T--;
    }
}