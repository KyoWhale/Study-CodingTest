// 21:05 ~ 
#include <iostream>
#include <queue>
using namespace std;

int travel[100003];
int visited[100003];
int N, K;

int main() {
    fill(visited, visited+100001, -1);
    
    cin >> N >> K;

    if (K < N) {
        cout << N - K << "\n";
        for (int i = N; i >= K; i--) {
            cout << i << " ";
        }
        return 0;
    }

    priority_queue<pair<int, int> > pq;
    visited[N] = 100002;
    pq.push({0, N});
    while(!pq.empty()) {
        auto[cost, cur] = pq.top(); pq.pop();
        
        if (cur == K) {
            cout << -cost << "\n";
            break;
        }

        if (0 <= cur-1 && visited[cur - 1] == -1) {
            pq.push({cost - 1, cur - 1});
            visited[cur-1] = cur;
        }
        if (cur + 1 < 100001 && visited[cur + 1] == -1) {
            pq.push({cost - 1, cur + 1});
            visited[cur+1] = cur;
        }
        if (cur != 0 && 2 * cur < 100001 && visited[2 * cur] == -1) {
            pq.push({cost - 1, cur * 2});
            visited[cur*2] = cur;
        }
    }

    // for (int i = 1; i <= 20; i++) {
    //     cout.width(2);
    //     cout << i << " ";
    // }
    // cout << "\n";

    // for (int i = 1; i <= 20; i++) {
    //     cout.width(2);
    //     if (visited[i] == -1)
    //         cout << "- ";
    //     else
    //         cout << visited[i] << " ";
    // }
    // cout << "\n";

    int cur = K;
    while (cur != N) {
        travel[visited[cur]] = cur;
        cur = visited[cur];
    }
    travel[visited[N]] = N;

    cur = N;
    while (cur != K) {
        cout << cur << " ";
        cur = travel[cur];
    }
    cout << K;
}