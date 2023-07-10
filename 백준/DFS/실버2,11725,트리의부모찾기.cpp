// 15:10 ~ 15:24 X 유니온 파인드 문제였는데 c++로 처음이다보니 거부감 들어서 피함
// ~ 15:35 https://jaimemin.tistory.com/585

#include <iostream>
#include <vector>
using namespace std;

int N;
int parent[100001];
bool visited[100001];
vector<int> connections[100001];

void findParent(int x) {
    visited[x] = true;

    for (int i = 0; i < connections[x].size(); i++) {
        int current = connections[x][i];

        if (visited[current]) continue;
        parent[current] = x;
        findParent(current);
    }
}

int main() {
    cin >> N;
    int x, y;
    for (int i = 0; i < N-1; i++) {
        cin >> x >> y;
        connections[x].push_back(y);
        connections[y].push_back(x);
    }

    findParent(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }
}