// 16:50 ~ 
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N, M;
string table[1001];
bool visited[2][1001][1001];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> table[i];
    }

    priority_queue<tuple< int, int, int, int> > q;
    q.emplace(-1, 0, 0, 0);
    visited[0][0][0] = true;
    while (!q.empty()) {
        auto[cost, smash, y, x] = q.top(); q.pop();
        if (y == N-1 && x == M-1) {
            cout << -cost;
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
            if (visited[smash][ny][nx]) continue;
            if (table[ny][nx] == '0') {
                q.emplace(cost-1, smash, ny, nx);
                visited[smash][ny][nx] = true;
            }
            else if (table[ny][nx] == '1' && smash == 0) {
                q.emplace(cost-1, smash+1, ny, nx);
                visited[smash][ny][nx] = true;
            }
        }
    }
    cout << -1;
}