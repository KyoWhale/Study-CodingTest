// 14:17 ~ 14:46
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

bool visited[MAX];

int main() {
    int a, b;
    cin >> a >> b;

    priority_queue<pair<int, int>> q;
    q.push({0, a});
    visited[a] = true;
    while (!q.empty()) {
        auto cur = q.top(); q.pop();
        visited[cur.second] = true;
        if (cur.second == b) {
            cout << -cur.first;
            break;
        }
        if (cur.second-1 >= 0 && visited[cur.second-1] == false) {
            q.push({cur.first-1, cur.second-1});
        }
        if (cur.second+1 < MAX && visited[cur.second+1] == false) {
            q.push({cur.first-1, cur.second+1});
        }
        if (cur.second*2 < MAX && visited[cur.second*2] == false) {
            q.push({cur.first, cur.second*2});
        }
    }
}