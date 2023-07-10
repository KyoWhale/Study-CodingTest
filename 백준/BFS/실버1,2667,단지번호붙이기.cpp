// 16:36 ~ 17:07

#include <iostream>
#include <queue>
#include <list>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int N;
int graph[26][26];

int bfs(int x, int y) {
    queue< pair<int, int> > q;
    q.push(make_pair(x,y));

    int cnt = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (graph[y][x] == 0) continue;

        graph[y][x] = 0;
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || N <= nx || N <= ny) continue;
            if (graph[ny][nx] == 1)
                q.push(make_pair(nx,ny));
        }
    }

    return cnt;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d", &graph[i][j]);

    int cnt = 0;
    list<int> area;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int result = bfs(j, i);
            if(result > 0) {
                cnt++;
                area.push_back(result);
            }
        }
    }
    area.sort();

    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        cout << area.front() << "\n";
        area.pop_front();
    }
}