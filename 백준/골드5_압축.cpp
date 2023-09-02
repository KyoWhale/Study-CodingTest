#include <iostream>
#include <vector>
using namespace std;

string s;
int length;
int visited[50] = { 0 };

int dfs(int idx) {
    int cnt = 0;

    for (int i = idx; i < length; i++)
    {
        if (s[i] == '(' && visited[i] == 0) {
            int num = s[i-1] - '0';
            visited[i] = 1;
            cnt--;
            cnt += num * dfs(i+1);
            continue;
        }
        if (s[i] == ')' && visited[i] == 0) {
            visited[i] = 1;
            return cnt;
        }
        if (visited[i] == 0) {
            visited[i] = 1;
            cnt++;
            continue;
        }
    }

    return cnt;
}

int main() {
    cin >> s;
    length = s.length();

    cout << dfs(0);
}