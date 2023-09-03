// 14:49 ~ 16:27
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int T, Y, X;
queue<pair<int, int> > q;
map<char, vector<pair<int, int> > > doorMap;
bool keys[30];
string keystr;
string table[101];
bool visited[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void action(int y, int x) {
    if (table[y][x] == '.' || table[y][x] == '$') {
        q.push({y, x});
    }
    else if (table[y][x] >= 'a' && table[y][x] <= 'z') {
        keys[table[y][x] - 'a'] = true;
        q.push({y, x});
        char upper = table[y][x] - 'a' + 'A';
        if (doorMap.find(upper) != doorMap.end()) {
            for (int i = 0; i < doorMap[upper].size(); i++) {
                q.push(doorMap[upper][i]);
            }
            doorMap[upper].clear();
        }
    }
    else if (table[y][x] >= 'A' && table[y][x] <= 'Z') {
        if (keys[table[y][x] - 'A']) {
            q.push({y, x});
        }
        else {
            doorMap[table[y][x]].push_back({y, x});
        }
    }
}

int solution() {
    int cnt = 0;
    cin >> Y >> X;
    for (int i = 0; i < Y; i++) {
        cin >> table[i];
    }
    cin >> keystr;
    if (keystr != "0") {
        for (int i = 0; i < keystr.length(); i++) {
            keys[keystr[i] - 'a'] = true;
        }
    }

    for (int i = 0; i < Y; i++) {
        action(i, 0);
        action(i, X-1);
    }
    for (int i = 0; i < X; i++) {
        action(0, i);
        action(Y-1, i);
    }

    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first; q.pop();
        if (visited[y][x]) continue; visited[y][x] = true;
        if (table[y][x] == '$') cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= X || ny >= Y || visited[ny][nx]) continue;
            action(ny, nx);
        }
    }

    cout << cnt << "\n";
    return cnt;
}

int main() {
    cin >> T;
    vector<int> answer;

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 30; j++) {
            doorMap.clear();
            keys[j] = false;
        }
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 101; k++)
                visited[j][k] = false;
        }
        answer.push_back(solution());
    }

    // for (int i = 0; i < answer.size(); i++) {
    //     cout << answer[i] << "\n";
    // }
}

// 2
// 2 2
// $$
// $$
// 0
// 3 3
// ***
// Z$*
// ***
// z