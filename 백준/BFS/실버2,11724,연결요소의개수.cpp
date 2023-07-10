// 17:13 ~ 17:41

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int graph[1001][1001];
int visited[1001];

bool bfs(int start) {
    bool hadVisited = false;

    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if (visited[node]) continue;
        visited[node] = true;
        hadVisited = true;

        for (int i = 1; i <= N; i++) {
            if (graph[node][i] == 1 && visited[i] == false) {
                q.push(i);
            }
        }
    }

    return hadVisited;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (bfs(i)) {
            cnt++;
        }
    }

    cout << cnt;
}