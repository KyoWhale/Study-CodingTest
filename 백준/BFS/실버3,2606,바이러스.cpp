// 16:16 ~ 16:33
// visit의 위치가 중요

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int graph[101][101];
int visited[101];

int bfs(int start) {
    visited[start] = true;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (graph[start][i] == 1 && i != start)
            q.push(i);
    }

    int cnt = 0;
    while(!q.empty()) {
        int des = q.front();
        q.pop();

        if (visited[des]) continue;
        visited[des] = true;
        cnt++;

        for (int i = 1; i <= N; i++) {
            if (graph[des][i] == 1 && des != i) {
                q.push(i);
            }
        }
    }

    return cnt;
}

int main() {
    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;

        graph[start][end] = 1;
        graph[end][start] = 1;
    }

    cout << bfs(1);
}