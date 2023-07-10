// 12:39 ~ 13:46

#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int graph[1001][1001];
bool visited[1001];

// while 루프로 dfs 돌려보려고 시도하다가 막혀서 바꿨음
// 아마 한 정점에서 가능한 간선을 탐색할 때 추가하는 곳에서, 다음 탐색 정점에서 추가 순서가 꼬였을 듯함
void dfs(int start, int end) {
    if (graph[start][end] == 0) return;
    if (visited[end]) return;
    visited[end] = true;
    cout << " " << end;

    for (int i = 1; i <= N; i++) {
        dfs(end, i);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    cout << v;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            int hasEdge = graph[cur][i];
            if (hasEdge == 0) continue;

            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                cout << " " << i;
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    visited[V] = true;
    cout << V;
    for(int i = 1; i <= N; i++)
        dfs(V, i);
    cout << "\n";

    for (int i = 0; i < N+1; i++)
        visited[i] = false;

    bfs(V);
}