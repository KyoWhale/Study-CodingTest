// 11:50 ~ 13:40
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string table[1501];
bool visited[1501][1501];
bool ice_visited[1501][1501];
int row, col, day = 0;
vector<pair<int, int> > L;
queue<pair<int, int> > q;
queue<pair<int, int> > next_q;
queue<pair<int, int> > melt;
queue<pair<int, int> > next_melt;
bool meet = false;

bool OOB(int y, int x) {
    return x < 0 || x >= row || y < 0 || y >= col;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> col >> row;

    for (int i = 0; i < col; i++) {
        cin >> table[i];
        for (int j = 0; j < row; j++) 
            if (table[i][j] == 'L') {
                L.push_back({i, j});
                melt.push({i, j});
            }
            else if (table[i][j] != 'X')
                melt.push({i, j});
    }
    q.push(L[0]);
    table[L[0].first][L[0].second] = '.';
    visited[L[0].first][L[0].second] = true;

    while (!meet) {
        while (!melt.empty()) {
            auto cur = melt.front(); melt.pop();
            ice_visited[cur.first][cur.second] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = cur.second + dx[i];
                int ny = cur.first + dy[i];
                if (OOB(ny, nx) || ice_visited[ny][nx]) continue;
                if (table[ny][nx] == 'X') next_melt.push({ny, nx});
                ice_visited[ny][nx] = true;
            }
        }
        while (!next_melt.empty()) {
            auto cur = next_melt.front(); next_melt.pop();
            table[cur.first][cur.second] = '.';
            melt.push(cur);
        }
        day++;

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.second + dx[i];
                int ny = cur.first + dy[i];
                if (OOB(ny, nx) || visited[ny][nx]) continue;
                if (table[ny][nx] == 'X') {
                    visited[ny][nx] = true;
                    next_q.push({ny, nx});
                    continue;
                }
                else if (table[ny][nx] == 'L') {
                    meet = true;
                    break;
                }
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
        while (!next_q.empty()) {
            q.push(next_q.front()); next_q.pop();
        }
    }

    cout << day;
}