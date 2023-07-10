// 13:48 ~ 15:22
// 테이블 범위 밖인지 확인하는 코드에서 최대 행(N) 과 행을 확인해야하는데 최대 열(M)과 행을 확인함

#include <iostream>
#include <iomanip>
#include <deque>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int graph[101][101];
int step[101][101];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < M; j++) {
            graph[i][j] = line[j] - '0';
            step[i][j] = INT32_MAX;
        }
    }

    deque<pair<int, int> > q;
    q.push_front(make_pair(0,0));
    step[0][0] = 1;

    while (!q.empty()) {
        pair<int, int> coor = q.front();
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = coor.first+dx[i];
            int ny = coor.second+dy[i];

            if (nx < 0 || ny < 0 || M <= nx || N <= ny) continue;
            if (graph[ny][nx] == 0) continue;
            if (step[ny][nx] > step[coor.second][coor.first]+1) {
                step[ny][nx] = step[coor.second][coor.first]+1;
                q.push_back(make_pair(nx,ny));
            }
        }
    }
    
    // cout << "\n";
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         if (step[i][j] == INT32_MAX)
    //             cout << "  - ";
    //         else
    //             cout << std::setw(3) << step[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << step[N-1][M-1];
}